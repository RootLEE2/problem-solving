# ver.1  208ms
N = int(input())
ju = list(map(int, input().split()))
sa = list(map(int, input().split()))
ju.sort(); sa.sort(); 
j = 0
for i in range(N):
  if ju[j] < sa[i]:
    j += 1
if j < (N+1)//2:
  print("NO")
else:
  print("YES")


# ver.2  168ms
N = int(input())
ju = list(map(int, input().split()))
sa = list(map(int, input().split()))
ju.sort(); sa.sort(); 
val = (N-1)//2
for i in range(val+1):
  if sa[val+i] <= ju[i]:
    print("NO")
    exit()
print("YES")


# ver.3  160ms
import sys
input = sys.stdin.readline
N = int(input())
ju = list(map(int, input().split()))
sa = list(map(int, input().split()))
ju.sort(); sa.sort(); 
val = (N-1)//2
for i in range(val+1):
  if sa[val+i] <= ju[i]:
    print("NO")
    exit()
print("YES")


# ver.4  192ms
N = int(input())
ju = list(map(int, input().split()))
sa = list(map(int, input().split()))
ju.sort(); sa.sort(); 
val = N//2; cnt = 0; 
for i in range(val+1):
  if ju[i] < sa[val+i]:
    cnt += 1
if val < cnt:
  print("YES")
else:
  print("NO")


# ver.5  176ms
import sys
input = sys.stdin.readline
N = int(input())
ju = list(map(int, input().split()))
sa = list(map(int, input().split()))
ju.sort(); sa.sort(); 
val = N//2; cnt = 0; 
for i in range(val+1):
  if ju[i] < sa[val+i]:
    cnt += 1
if val < cnt:
  print("YES")
else:
  print("NO")
