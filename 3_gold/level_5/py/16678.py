import sys
input = sys.stdin.readline
N = int(input())
a = [int(input()) for _ in range(N)]
a.sort()
cnt = 0; temp = 1; 
for i in range(N):
  if temp <= a[i]:
    cnt += a[i] - temp
    temp += 1
print(cnt)