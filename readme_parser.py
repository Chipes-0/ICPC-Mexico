import os
import re

ROOT = "."  # raíz del repo

def parse_solution(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()

    def extract(pattern):
        match = re.search(pattern, content, re.DOTALL)
        return match.group(1).strip() if match else "N/A"

    return {
        "problem": extract(r"PROBLEM:\s*(.*)"),
        "time": extract(r"TIME_COMPLEXITY:\s*(.*)"),
        "space": extract(r"SPACE_COMPLEXITY:\s*(.*)")
    }

def is_contest_folder(name):
    return name.startswith("ICPC")

def generate():
    for folder in os.listdir(ROOT):
        folder_path = os.path.join(ROOT, folder)

        if not os.path.isdir(folder_path):
            continue

        if not is_contest_folder(folder):
            continue

        readme = f"# {folder}\n\n"

        found = False

        for root, _, files in os.walk(folder_path):
            for file in files:
                if file.endswith(".cpp"):
                    found = True
                    path = os.path.join(root, file)
                    data = parse_solution(path)

                    rel_path = os.path.relpath(path, folder_path)

                    readme += f"## {rel_path}\n"
                    readme += f"- 🔗 [Problema]({data['problem']})\n"
                    readme += f"- ⏱ Tiempo: `{data['time']}`\n"
                    readme += f"- 💾 Espacio: `{data['space']}`\n\n"

        if found:
            with open(os.path.join(folder_path, "README.md"), "w", encoding="utf-8") as f:
                f.write(readme)

def generate_global():
    readme = "# Resumen de problemas\n\n"

    for folder in os.listdir(ROOT):
        if not is_contest_folder(folder):
            continue

        readme += f"## {folder}\n\n"

        folder_path = os.path.join(ROOT, folder)

        for root, _, files in os.walk(folder_path):
            for file in files:
                if file.endswith(".cpp"):
                    path = os.path.join(root, file)
                    data = parse_solution(path)

                    readme += f"- [{file}]({path}) → `{data['time']}`\n"

        readme += "\n"

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(readme)

if __name__ == "__main__":
    generate()
    generate_global()