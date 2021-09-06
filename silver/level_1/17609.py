def is_palindrome(s):
  for i in range(len(s)//2):
    if s[i] != s[-(i+1)]:
      return 1
  return 0

T = int(input())
for _ in range(T):
  S = input()
  result = 0
  for i in range(len(S)//2):
    if S[i] != S[-(i+1)]:
      if S[i+1] != S[-(i+1)] and S[i] != S[-(i+2)]:
        result = 2
        break
      else:
        result = is_palindrome(S[i+1:-i]) + is_palindrome(S[i:-i-1])
  print(result)