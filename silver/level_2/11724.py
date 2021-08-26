import sys
from collections import deque
input = sys.stdin.readline

def bfs(vertex):
  queue = deque()
  queue.append(vertex)

  while queue:
    v = queue.popleft()
    for u in graph[v]:
      if not visited[u]:
        visited[u] = True
        queue.append(u)

N,M = map(int, input().split())
graph = [[] for _ in range(N+1)]
for _ in range(M):
  u,v = map(int, input().split())
  graph[u].append(v)
  graph[v].append(u)

visited = [False]*(N+1)
cnt = 0
for i in range(1,N+1):
  if not visited[i]:
    visited[i] = True
    cnt += 1
    bfs(i)
print(cnt)
