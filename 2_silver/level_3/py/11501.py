# ver.1
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
  N = int(input())
  stock = list(map(int, input().split()))
  result = 0; cnt = 0; temp = 0; 
  for i, element in enumerate(stock):
    if i != N-1 and element <= stock[i+1]:
      cnt += 1
      temp += element
    else:
      result += cnt * element - temp
      cnt = 0
      temp = 0
  print(result)


# ver.2  3928ms
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
  N = int(input())
  stock = list(map(int, input().split()))
  result = 0; max = stock[-1]; 
  for i in range(N-2,-1,-1):
    if stock[i] < max:
      result += max - stock[i]
    else:
      max = stock[i]
  print(result)
