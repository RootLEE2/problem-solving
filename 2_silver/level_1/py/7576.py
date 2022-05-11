import sys
from collections import deque
input = sys.stdin.readline

def bfs():
  queue = deque()
  for i in point:
    queue.append(i)
  last = 1
  while queue:
    x,y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if nx < 0 or ny < 0 or N <= nx or M <= ny:
        continue
      if graph[nx][ny] == -1:
        continue
      if graph[nx][ny] == 0:
        graph[nx][ny] = graph[x][y] + 1
        if last < graph[nx][ny]:
          last = graph[nx][ny]
        queue.append((nx,ny))
  return last
    
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

M,N = map(int, input().split())
graph = []; point = []; 
for i in range(N):
  graph.append(list(map(int, input().split())))
  for j in range(M):
    if graph[i][j] == 1:
      point.append((i,j))

result = bfs()
for i in range(N):
  if 0 in graph[i]:
    print(-1)
    exit()
print(result-1)
