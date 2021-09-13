# ver.1  80ms
import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dp = [[0]*N for _ in range(N)]; dp[0][0] = 1; 

for i in range(N):
  for j in range(N):
    if i == N-1 and j == N-1:
      break
    if dp[i][j] == 0:
      continue
    
    jump = board[i][j]
    if i+jump < N:
      dp[i+jump][j] += dp[i][j]
    if j+jump < N:
      dp[i][j+jump] += dp[i][j]
print(dp[N-1][N-1])


# ver.2  메모리 초과
import sys
from collections import deque
input = sys.stdin.readline

def bfs():
  queue = deque()
  queue.append((0,0))

  while queue:
    x,y = queue.popleft()
    for i in range(2):
      nx = x + jump[x][y] * dx[i]
      ny = y + jump[x][y] * dy[i]

      if nx < 0 or ny < 0 or N <= nx or N <= ny:
        continue
      if jump[ny][nx] == 0:
        board[ny][nx] += board[x][y]
        continue
      else:
        board[nx][ny] += board[x][y]
        queue.append((nx,ny))

dx = [1, 0]
dy = [0, 1]
        
N = int(input())
jump = [list(map(int, input().split())) for _ in range(N)]
board = [[0]*N for _ in range(N)]; board[0][0] = 1; 

bfs()
print(board[N-1][N-1])