# 76ms ver.
N,M = map(int, input().split())
J = int(input())
start,end,cnt = 1,M,0

for _ in range(J):
  loc = int(input())
  if loc < start:
    cnt += start - loc
    end -= start - loc
    start = loc
  elif end < loc:
    cnt += loc - end
    start += loc - end
    end = loc

print(cnt)


# 80ms ver.
N,M = map(int, input().split())
J = int(input())
start,end,cnt = 1,M,0

for _ in range(J):
  loc = int(input())
  if not start <= loc <= end:
    if loc < start:
      temp = start - loc
      start = loc
      end -= temp
      cnt += temp
    else:
      temp = loc - end
      start += temp
      end = loc
      cnt += temp

print(cnt)