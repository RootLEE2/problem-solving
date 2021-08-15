B,C,D = map(int, input().split())
bPrice = list(map(int, input().split()))
cPrice = list(map(int, input().split()))
dPrice = list(map(int, input().split()))

discountNum = min(B,C,D)
bPrice.sort(reverse=True)
cPrice.sort(reverse=True)
dPrice.sort(reverse=True)

beforePrice = sum(bPrice) + sum(cPrice) + sum(dPrice)
afterPrice = (sum(bPrice[:discountNum])+sum(cPrice[:discountNum])+sum(dPrice[:discountNum])) * 90 // 100
afterPrice += sum(bPrice[discountNum:])+sum(cPrice[discountNum:])+sum(dPrice[discountNum:])

print(beforePrice)
print(afterPrice)