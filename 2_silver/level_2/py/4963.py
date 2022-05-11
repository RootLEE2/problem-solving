import sys
from collections import deque
input = sys.stdin.readline

def bfs(y,x):
  queue = deque()
  queue.append((y,x))

  while queue:
    y,x = queue.popleft()
    for i in range(8):
      nx = x + dx[i]
      ny = y + dy[i]

      if nx < 0 or ny < 0 or w <= nx or h <= ny:
        continue
      if graph[ny][nx] == 0:
        continue
      if graph[ny][nx] == 1:
        graph[ny][nx] = 0
        queue.append((ny,nx))
    
dx = [0, 1, 1, 1, 0, -1, -1, -1]
dy = [1, 1, 0, -1, -1, -1, 0, 1]

while True:
  w,h = map(int, input().split())
  if w == h == 0:
    break

  graph = []
  for _ in range(h):
    graph.append(list(map(int, input().split())))

  cnt = 0
  for i in range(h):
    for j in range(w):
      if graph[i][j] == 1:
        bfs(i,j)
        cnt += 1
  print(cnt)
