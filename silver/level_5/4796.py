# ver.1
import sys
cnt,tmp = 1,0
while True:
  L,P,V = map(int, sys.stdin.readline().split())
  if L == 0 and P == 0 and V == 0:
    break
  if V%P <= L:
    tmp = (V//P)*L + (V%P)
  else:
    tmp = (V//P)*L + L
  print("Case {}: {}".format(cnt, tmp))
  cnt += 1


# ver.2
import sys
cnt = 1
while True:
  L,P,V = map(int, sys.stdin.readline().split())
  if L == P == V == 0:
    break
  print("Case {}: {}".format(cnt, (V//P)*L + (V%P if V%P <= L else L)))
  cnt += 1