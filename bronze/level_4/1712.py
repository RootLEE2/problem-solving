A,B,C = map(int, input().split())

if B < C:
  n = A // (C - B) + 1
else:
  n = -1

print(n)