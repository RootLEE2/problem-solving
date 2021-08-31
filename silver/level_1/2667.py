# ver.1  76ms
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
print(len(cnt))
for element in cnt:
  print(element)


# ver.2  68ms
N = int(input())
graph = []
cnt = 0; cntList = []; 
for _ in range(N):
  graph.append(list(map(int, input())))

def dfs(x,y):
  if x < 0 or y < 0 or N <= x or N <= y:
    return
  if graph[x][y] == 0:
    return

  global cnt
  cnt += 1
  graph[x][y] = 0

  dfs(x+1,y)
  dfs(x-1,y)
  dfs(x,y+1)
  dfs(x,y-1)

for i in range(N):
  for j in range(N):
    if graph[i][j] == 1:
      dfs(i,j)
      cntList.append(cnt)
      cnt = 0

cntList.sort()
print(len(cntList))
for element in cntList:
  print(element)
