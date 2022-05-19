# ver.1  4164ms
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
  N = int(input())
  A = []
  for i in range(N):
    A.append(list(map(int, input().split())))

  A.sort(key = lambda x: x[0])
  cnt = 1; max = A[0][1]
  for i in range(1,N):
    if A[i][1] < max:
      cnt += 1
      max = A[i][1]
  print(cnt)


# ver.2  2476ms
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
  N = int(input())
  A = [0]*(N+1)
  for i in range(N):
    doc, face = map(int, input().split())
    A[doc] = face

  cnt = 1; max = A[1]
  for i in range(2,N+1):
    if A[i] < max:
      cnt += 1
      max = A[i]
  print(cnt)