import sys
input = sys.stdin.readline

T = int(input())
change = [25, 10, 5, 1]

for _ in range(T):
  C = int(input())
  for i in range(3):
    print(C//change[i], end=' ')
    C %= change[i]
  print(C//change[3])
