# ver.1
N = int(input())
h = list(map(int, input().split()))

day,two = 0,0
for i in range(N):
  day += h[i]
  two += h[i]//2

if day%3 != 0:
  print("NO")
else:
  if day//3 <= two:
    print("YES")
  else:
    print("NO")


# ver.2 (다른 사람 코드)
import sys
input = sys.stdin.readline

N = int(input())
h = list(map(int, input().split()))
q = sum([i//2 for i in h])
r = sum([i%2 for i in h])

if q >= r and (q - r)%3 == 0:
    print('YES')
else:
    print('NO')