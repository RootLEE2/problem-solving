# ver.1  80ms
N = int(input())
round1 = list(map(int, input().split()))
round2 = list(map(int, input().split()))
result = 0
for i in range(N):
  if 0 < round1[i]:
    result += round1[i]
  else:
    result += -1 * round1[i]
  if 0 < round2[i]:
    result += round2[i]
  else:
    result += -1 * round2[i]
print(result)


# ver.2  72ms
N = int(input())
round1 = list(map(int, input().split()))
round2 = list(map(int, input().split()))
result = sum(list(map(abs, round1)))
result += sum(list(map(abs, round2)))
print(result)


# ver.3  72ms
input(); input()
print(2 * sum(map(lambda x:abs(int(x)), input().split())))
