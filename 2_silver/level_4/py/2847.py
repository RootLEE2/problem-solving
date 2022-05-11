# ver.1  84ms
import sys
input = sys.stdin.readline

N = int(input())
point = [int(input()) for _ in range(N)]
cnt = 0

for i in range(2,N+1):
  if point[-i+1] <= point[-i]:
    cnt += point[-i] - point[-i+1] + 1
    point[-i] = point[-i+1] - 1
print(cnt)


# ver.2  80ms
import sys
input = sys.stdin.readline

N = int(input())
point = [int(input()) for _ in range(N)]
cnt = 0

pointTemp = point[-1]
for i in range(N-2,-1,-1):
  if pointTemp <= point[i]:
    cnt += point[i] - pointTemp + 1
    pointTemp -= 1
  else:
    pointTemp = point[i]
print(cnt)
