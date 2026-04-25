"""
PROBLEM: https://codeforces.com/gym/106495/problem/B
TIME_COMPLEXITY: O(N * L)
SPACE_COMPLEXITY: O(L)

INPUT:
Test case 1:
4
This example shows a value
Of 1000000000 without being compressed to 10^{9}
Which is annoying when read. $ S_{10} = 2^{100000} + 780000 $
My ID is RA180000 but that was back in the year 20000


OUTPUT:
This example shows a value
Of 10^{9} without being compressed to 10^{9}
Which is annoying when read. $ S_{10} = 2^{100000} + 7.8\cdot10^{5} $
My ID is RA180000 but that was back in the year 2\cdot10^{4}
"""

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

