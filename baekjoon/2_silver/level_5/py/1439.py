# ver.1  88ms
S = input()
cnt = {'0':0, '1':0}
s = ['1', '0']

idx = 0
for _ in range(len(S)):
  cnt[S[idx]] += 1
  temp = S[idx:].find(s[int(S[idx])])
  if temp == -1:
    break
  idx += temp
print(min(cnt['0'], cnt['1']))


# ver.2  84ms
S = input()
cnt = 0

if S[0] == '0':
  for i in range(len(S)-1):
    if S[i] == '0' and S[i+1] == '1':
      cnt += 1
else:
  for i in range(len(S)-1):
    if S[i] == '1' and S[i+1] == '0':
      cnt += 1
print(cnt)
