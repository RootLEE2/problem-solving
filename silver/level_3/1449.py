# ver.1  84ms
import sys
input = sys.stdin.readline

N,L = map(int, input().split())
loc = list(map(int, input().split()))
loc.sort()

checked = [False]*N; cnt = 0; 
for i in range(N):
  if not checked[i]:
    checked[i] = True
    cnt += 1
    temp = loc[i] + L - 1
    for j in range(i+1,N):
      if loc[j] <= temp:
        checked[j] = True
print(cnt)


# ver.2  88ms
import sys
input = sys.stdin.readline

N,L = map(int, input().split())
loc = list(map(int, input().split()))
loc.sort()

cnt = 1; end = loc[0] + L - 1; 
for element in loc:
  if element <= end:
    continue
  cnt += 1
  end = element + L - 1
print(cnt)
