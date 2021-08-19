# ver.1
N = int(input())
for i in range(1,92683):
  N -= i
  if N < i+1 or N <= 0:
    break
print(i)


# ver.2
N = int(input())
sum = 0
for i in range(1,92683):
  sum += i
  if sum > N:
    break
print(i-1)