from collections import deque

def bfs():
  queue = deque()
  queue.append((0,0))

  while queue:
    x,y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if nx < 0 or ny < 0 or N <= nx or M <= ny:
        continue
      if graph[nx][ny] == 0:
        continue
      if graph[nx][ny] == 1:
        graph[nx][ny] = graph[x][y] + 1
        queue.append((nx,ny))

  return graph[N-1][M-1]
    
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

N,M = map(int, input().split())
graph = []
for _ in range(N):
  graph.append(list(map(int, input())))

print(bfs())
