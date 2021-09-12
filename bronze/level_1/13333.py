# ver.1  68ms
n = int(input())
t = sorted(list(map(int, input().split())))
for k in range(n,-1,-1):
  if k <= t[-k]:
    print(k)
    break