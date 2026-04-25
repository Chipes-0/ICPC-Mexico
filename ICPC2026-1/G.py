"""
PROBLEM: https://codeforces.com/gym/106495/problem/G
TIME_COMPLEXITY: O(N)
SPACE_COMPLEXITY: O(N)

INPUT:
Test case 1:
5
1 2 3 4 5

OUTPUT:
0

Test case 2:
5
1 1 2 4 4

OUTPUT:
2

test case 3:
3
3 2 2

OUTPUT:
1
"""
n = int(input())
s = set(map(int, input().split()))

print(n - len(s))