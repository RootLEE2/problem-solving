import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(y, x):
  if x < 0 or x >= M or y < 0 or y >= N:
    return
  
  if graph[y][x]:
    graph[y][x] = False
    dfs(y-1, x)
    dfs(y+1, x)
    dfs(y, x-1)
    dfs(y, x+1)        
  return

T = int(input())
for _ in range(T):
  M,N,K = map(int, input().split())
  graph = [[False]*M for i in range(N)]
  result = 0

  for i in range(K):
    X,Y = map(int, input().split())
    graph[Y][X] = True

  for i in range(N):
    for j in range(M):
      if graph[i][j]:
        dfs(i, j)
        result += 1
  print(result)
  