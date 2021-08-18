# ver.1
board = input()
cnt,pre = 0,-1
result = ''

for _ in range(len(board)):
  idx = board[pre+1:].find('.')
  if idx == -1:
    idx = len(board[pre+1:])

  temp = idx
  if temp % 2 == 0:
    result += 'AAAA' * (temp // 4)
    temp %= 4
    result += 'BB' * (temp // 2)
  else:
    result = '-1'
    break

  if idx == len(board[pre+1:]):
    break
  else:
    result += '.'
  pre += idx+1

print(result)


# ver.2
board = list(map(str, input().split('.')))
result = ''

for i in board:
  temp = len(i)
  if temp % 2 == 0:
    result += 'AAAA' * (temp // 4)
    temp %= 4
    result += 'BB' * (temp // 2)
    result += '.'
  else:
    result = '-1 '
    break

print(result[:-1])