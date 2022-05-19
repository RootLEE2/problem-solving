# ver.1
A,B = input().split()
if len(A) > len(B):
  B = '0'*(len(A)-len(B)) + B
else:
  A = '0'*(len(B)-len(A)) + A

result = ''
count = 0
for i in range (len(A)):
  temp = count + int(A[-(i+1)]) + int(B[-(i+1)])
  if temp > 1:
    count = 1
    result = str(temp%2) + result
  else:
    count = 0
    result = str(temp%2) + result
if count == 1:
  result = '1' + result

if '1' not in result:
  print('0')
else:
  temp = result.index('1')
  print(result[temp:])


# ver.2
a,b = input().split()
a = int("0b"+a, 2)
b = int("0b"+b, 2)
print(bin(a+b)[2:])