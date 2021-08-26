T = int(input())
cnt = [0]*3

if T % 10 != 0:
  print(-1)
else:
  cnt[0] = T // 300
  T = T % 300
  cnt[1] = T // 60
  T = T % 60
  cnt[2] = T // 10
  print(cnt[0], cnt[1], cnt[2])