# ver.1  404ms
import sys
input = sys.stdin.readline
N = int(input())
time = [list(map(int, input().split())) for _ in range(N)]
time.sort(key=lambda t: (t[1], t[0]))
cnt = 0; end = 0; 
for element in time:
  if end <= element[0]:
    cnt += 1
    end = element[1]
print(cnt)


# ver.2  308ms  list보다는 tuple이 더 빠르다.
import sys
input = sys.stdin.readline
N = int(input())
time = [tuple(map(int, input().split())) for _ in range(N)]
time.sort(key=lambda t: (t[1], t[0]))
cnt = 0; end = 0; 
for element in time:
  if end <= element[0]:
    cnt += 1
    end = element[1]
print(cnt)


# ver.3  312ms  list 선언과 동시에 append하는 것이 더 빠르다.
import sys
input = sys.stdin.readline
N = int(input())
time = []
for _ in range(N):
  a,b = map(int, input().split())
  time.append((a,b))
time.sort(key=lambda t: (t[1], t[0]))
cnt = 0; end = 0; 
for element in time:
  if end <= element[0]:
    cnt += 1
    end = element[1]
print(cnt)
