## https://codeforces.com/gym/106495/problem/B

n = int(input())

for i in range(n):
    line = input().split(" ")
    for windex, word in enumerate(line):
        word = word.lstrip("0")
        if len(word) > 4 and word.isdigit() and word[-4 :] == "0000":
            zeros = 0
            index = len(word) - 1
            while index >= 0 and word[index] == "0":
                zeros += 1
                index -= 1
            if index == 0 and word[index] == "1":
                line[windex] = "10^{" + str(zeros) + "}"
            else:
                line[windex] = word[0] + ("." if index > 0 else "") + word[1:index+1] + "\\cdot10^{" + str(len(word) - 1) + "}"
    print(" ".join(line))

