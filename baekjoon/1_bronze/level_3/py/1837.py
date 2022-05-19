P,K = map(int, input().split())

flag = True
for i in range(2,K):
  if P%(i) == 0:
    print("BAD", i)
    flag = False
    break
if flag:
  print("GOOD")