# ver.1  76ms
N = int(input())
temp,cnt = 11,1
while not N < temp:
  temp = temp*10 + 1
  cnt += 1
print(cnt)


# ver.2  76ms
N = input()
if int(N) < 11:
  print(1)
elif int(N) < int(len(N)*'1'):
  print(len(N)-1)
else:
  print(len(N))