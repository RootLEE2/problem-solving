# ver.1  76ms
k = int(input())
F = input()
M = input()
total = len(M)
same = 0
for i in range(total):
  if F[i] == M[i]:
    same += 1

if same == 0:
  print(total-k)
elif same == total:
  print(k)
else:
  if same < k:
    print(total+same-k)
  else:
    print(total-same+k)


# ver.2  84ms
k = int(input())
F = input()
M = input()
total = len(M)
same = 0
for i in range(total):
  if F[i] == M[i]:
    same += 1

if same < k:
  print(total+same-k)
else:
  print(total-same+k)


# ver.3  84ms
k = int(input())
F = input()
M = input()
total = len(M)
same = 0
for i, element in enumerate(M):
  if element == F[i]:
    same += 1
print(total + min(same,k) - max(same,k))


# ver.4  84ms
k = int(input())
ans = [f==m for f,m in zip(input(),input())]
total,same = len(ans), ans.count(1)
print(total + min(same,k) - max(same,k))


# ver.5  76ms
k = int(input())
ans = [f==m for f,m in zip(input(),input())]
total,same = len(ans), ans.count(1)
print(min(same,k) + min(total-same,total-k))
