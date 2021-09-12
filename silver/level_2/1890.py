# ver.1  80ms
# import sys
# input = sys.stdin.readline

# N = int(input())
# board = [list(map(int, input().split())) for _ in range(N)]
# dp = [[0]*N for _ in range(N)]; dp[0][0] = 1; 

# for i in range(N):
#   for j in range(N):
#     if i == N-1 and j == N-1:
#       break
#     if dp[i][j] == 0:
#       continue
    
#     jump = board[i][j]
#     if i+jump < N:
#       dp[i+jump][j] += dp[i][j]
#     if j+jump < N:
#       dp[i][j+jump] += dp[i][j]
# print(dp[N-1][N-1])


# ver.2
import sys
from collections import deque
input = sys.stdin.readline

def bfs():
  queue = deque()
  queue.append((0,0))

  while queue:
    x,y = queue.popleft()
    for i in range(8):
      nx = x + board[x][y] * dx[i]
      ny = y + dy[i]

      if nx < 0 or ny < 0 or w <= nx or h <= ny:
        continue
      if board[ny][nx] == 0:
        continue
      if board[ny][nx] == 1:
        board[ny][nx] = 0
        queue.append((ny,nx))

dx = [1, 0]
dy = [0, 1]
        
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dp = [[0]*N for _ in range(N)]; dp[0][0] = 1; 

cnt = 0
bfs()
print(cnt)