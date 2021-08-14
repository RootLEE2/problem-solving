# ver.1
N = int(input())

num = 0
for _ in range(N//3):
  if N % 5 == 0:
    num += N // 5
    break
  else:
    N -= 3

  if N < 3:
    if N == 0:
      num += 1
      break
    else:
      num = -1
      break
  num += 1

print(num)


# ver.2
N = int(input())
tmp = [i + (N-5*i) // 3 for i in range(N//5+1) if (N-5*i) % 3 == 0]
print(min(tmp) if len(tmp) != 0 else -1)