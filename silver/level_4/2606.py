import sys
input = sys.stdin.readline

def dfs(v):
  global cnt
  visited[v] = True
  cnt += 1

  for i in graph[v]:
    if not visited[i]:
      dfs(i)

C = int(input())
E = int(input())
graph = [[] for _ in range(C+1)]
visited = [False]*(C+1)
cnt = -1
for _ in range(E):
  a,b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

dfs(1)
print(cnt)