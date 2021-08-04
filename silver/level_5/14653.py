N,K,Q = map(int, input().split())
RList = list()
PList = list()

for i in range(1, K+1):
  R,P = map(str, input().split())
  RList.append(R)
  PList.append(P)

NAME = set(list(chr(65+i) for i in range(1, N)))
viewedList = set()
unviewedNum = int(RList[Q-1])
sameStart = RList.index(str(unviewedNum))

for i in range(sameStart, K):
  viewedList.add(PList[i])

if unviewedNum == 0:
  print(-1)
else:
  unviewedList = list(NAME - viewedList)
  unviewedList.sort()
  expectedNum = len(unviewedList)
  for i in range(expectedNum-1):
    print(unviewedList[i], end=' ')
  print(unviewedList[expectedNum-1])