# ver.1  248ms
import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  N = int(input())
  L = sorted(list(map(int, input().split())))
  cnt = []
  for i in range(N-2):
    cnt.append(L[i+2] - L[i])
  cnt.append(L[-1] - L[-2])
  print(max(cnt))


# ver.2  208ms
import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  N = int(input())
  L = sorted(list(map(int, input().split())))
  level = 0
  for i in range(N-2):
    if level < L[i+2] - L[i]:
      level = L[i+2] - L[i]
  if level < L[-1] - L[-2]:
    level = L[-1] - L[-2]
  print(level)
