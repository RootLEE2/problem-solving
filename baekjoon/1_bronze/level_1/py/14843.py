N = int(input())
sum = 0
for i in range(N):
  S,A,T,M = map(float, input().split())
  sum += S*(1+1/A)*(1+M/T)/4

P = int(input())
R = [sum]
for i in range(P):
  R.append(float(input()))

R.sort()
for i in range(P+1):
  if R[i] == sum:
    if i/(P+1)>=0.85:
      print('The total score of Younghoon "The God" is {0:.2f}.'.format(sum))
    else:
      print('The total score of Younghoon is {0:.2f}.'.format(sum))