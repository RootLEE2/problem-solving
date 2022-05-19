import sys

N,score,P = map(int, input().split())
data = list(map(int, sys.stdin.readline().split()))
data.append(score)
data.sort(reverse = True)

tmp = data.index(score)
if N == P:
  if tmp == P or data[tmp] == data[P]:
    print(-1)
  else:
    print(tmp+1)
else:
  print(tmp+1)