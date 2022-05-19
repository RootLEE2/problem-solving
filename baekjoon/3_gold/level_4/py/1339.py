# ver.1  76ms
N = int(input())
num = [input() for _ in range(N)]
dic = {}

for i in range(N):
  for j in range(0,len(num[i])):
    temp = num[i][-j-1]
    if temp in dic:
      dic[temp] += 10 ** j
    else:
      dic[temp] = 10 ** j

dic = sorted(dic.items(), key = lambda item: item[1], reverse = True)
sum,val = 0,9
for key,element in dic:
  sum += element * val
  val -= 1
print(sum)