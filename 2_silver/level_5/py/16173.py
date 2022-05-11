# ver.1  108ms
import sys
from collections import deque
input = sys.stdin.readline

def bfs():
  queue = deque()
  queue.append((0,0))

  while queue:
    x,y = queue.popleft()
    for i in range(2):
      nx = x + graph[x][y] * dx[i]
      ny = y + graph[x][y] * dy[i]

      if N <= nx or N <= ny:
        continue
      if graph[nx][ny] == 0:
        continue
      if graph[nx][ny] == -1:
        return True
      queue.append((nx,ny))
        
  return False

dx = [0, 1]
dy = [1, 0]

N = int(input())
graph = []
for _ in range(N):
  graph.append(list(map(int, input().split())))

if bfs():
  print("HaruHaru")
else:
  print("Hing")



# ver.2  76ms (다른 사람 코드 간단 수정)
import sys
input = sys.stdin.readline

def dfs(x,y):
  global flag
  if flag:
    return
  if N <= x or N <= y:
    return
  if graph[x][y] == -1:
    flag = True
    return

  jump = graph[x][y]
  if jump == 0:
    return
  dfs(x+jump, y)
  dfs(x, y+jump)

N = int(input())
graph = []
flag = False
for _ in range(N):
  graph.append(list(map(int, input().split())))

dfs(0, 0)
if flag:
  print("HaruHaru")
else:
  print("Hing")
