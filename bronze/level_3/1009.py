T = int(input())
for i in range(T):
  a, b = map(int, input().split())
  val = pow(a, b, 10)

  if val == 0:
    print(10)
  else: 
    print(val)