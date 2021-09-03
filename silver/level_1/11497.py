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
  cnt.append(L[-1] - L[-2])  # 사실 없어도 됨. 근데 있을 때 더 빠름..
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
  if level < L[-1] - L[-2]:  # 사실 없어도 됨. 근데 있을 때 더 빠름..
    level = L[-1] - L[-2]
  print(level)


# ver.3  260ms
import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
  N = int(input())
  L = sorted(list(map(int, input().split())))
  level = 0
  for i in range(N-2):
    level = max(level, L[i+2] - L[i])
  level = max(level, L[-1] - L[-2])  # 사실 없어도 됨. 근데 있을 때 더 빠름..
  print(level)
