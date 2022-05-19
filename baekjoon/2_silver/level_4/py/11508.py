# ver.1  4720ms
N = int(input())
C = [int(input()) for _ in range(N)]
C.sort(reverse=True)
for i in range(1, N//3+1):
  C.pop(2*i)
print(sum(C))


# ver.2  748ms
import sys
input = sys.stdin.readline
N = int(input())
C = [int(input()) for _ in range(N)]
C.sort(reverse=True)
for i in range(1, N//3+1):
  C.pop(2*i)
print(sum(C))


# ver.3  136ms
import sys
input = sys.stdin.readline
N = int(input())
C = [int(input()) for _ in range(N)]
C.sort(reverse=True)
result = 0
for i in range(0,N,3):
  result += sum(C[i:i+2])
print(result)