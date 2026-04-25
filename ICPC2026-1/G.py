## https://codeforces.com/gym/106495/problem/G
n = int(input())
s = set(map(int, input().split()))

print(n - len(s))