# ver.1  396ms
def is_palindrome(l,r):
  while l < r:
    if S[l] == S[r]:
      l += 1
      r -= 1
    else:
      return 1
  return 0

T = int(input())
for _ in range(T):
  S = input()
  l,r = 0,len(S) - 1
  result = 0
  while l < r:
    if S[l] == S[r]:
      l += 1
      r -= 1
    else:
      result = is_palindrome(l,r-1) + is_palindrome(l+1,r)
      if result == 0:
        result = 1
      break
  print(result)


# ver.2  148ms  다른 사람 코드(연구용)
import sys
input = sys.stdin.readline

def is_palindrome(s):
  return s[::-1] == s

def is_pseudo_pal(s):
  if len(s) == 2:
    return True
  if is_palindrome(s[1:]) or is_palindrome(s[:-1]):
    return True
  if s[0] != s[-1]:
    return False

  diff_i = 1
  for i in range(1,len(s)//2):
    if s[i] != s[~i]:
      diff_i = i
      break

  return is_pseudo_pal(s[diff_i:~diff_i+1])

T = int(input())
for _ in range(T):
  S = input().rstrip()
  result = 2
  if is_palindrome(S):
    result = 0
  elif is_pseudo_pal(S):
    result = 1
  print(result)
