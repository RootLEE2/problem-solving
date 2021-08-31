# ver.1 
def dfs(x,y):
  if x < 0 or y < 0 or N <= x or N <= y:
    return 0
  if graph[x][y] == 0:
    return 0

  graph[x][y] = 0
  return dfs(x+1,y) + dfs(x-1,y) + dfs(x,y+1) + dfs(x,y-1) + 1

N = int(input())
graph = []
for _ in range(N):
  graph.append(list(map(int, input())))

cnt = []
for i in range(N):
  for j in range(N):
    if graph[i][j] == 1:
      cnt.append(dfs(i,j))

cnt.sort()
num = len(cnt)
print(num)
for i in range(num):
  print(cnt[i])


# ver.2
N = int(input())
graph = []; cnt = 0; 
for _ in range(N):
  graph.append(list(map(int, input())))

def dfs(x,y):
  if x < 0 or y < 0 or N <= x or N <= y:
    return 0
  if graph[x][y] == 0:
    return 0

  graph[x][y] = 0
  return dfs(x+1,y) + dfs(x-1,y) + dfs(x,y+1) + dfs(x,y-1) + 1

cnt = []
for i in range(N):
  for j in range(N):
    if graph[i][j] == 1:
      cnt.append(dfs(i,j))

cnt.sort()
num = len(cnt)
print(num)
for i in range(num):
  print(cnt[i])