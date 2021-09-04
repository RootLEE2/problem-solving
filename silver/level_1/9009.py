# ver.1  92ms
import sys
input = sys.stdin.readline

fibo = [1,1]
for i in range(2,45):
  fibo.append(fibo[i-1] + fibo[i-2])

T = int(input())
for _ in range(T):
  n = int(input())
  result = []
  for i in reversed(fibo):
    if i <= n:
      result.append(i)
      n -= i
  for i in reversed(result):
    print(i, end=' ')