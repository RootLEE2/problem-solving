# ver.1  192ms
N = int(input())
km = list(map(int, input().split()))
price = list(map(int, input().split()))
minPrice = 0; start = 0; 
for i in range(1,N):
  if price[i] < price[start]:
    minPrice += sum(km[start:i]) * price[start]
    start = i
minPrice += sum(km[start:i]) * price[start]
print(minPrice)


# ver.2  152ms
N = int(input())
km = list(map(int, input().split()))
price = list(map(int, input().split()))
minPrice = price[0]; result = 0; 
for i in range(N-1):
  if price[i] < minPrice:
    minPrice = price[i]
  result += km[i] * minPrice
print(result)
