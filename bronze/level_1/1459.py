X,Y,W,S = map(int, input().split())
if X > Y:
  X,Y = Y,X

if S < 2*W:
  if S > W:
    print(X*S + (Y-X)*W)
  else:
    if (X+Y)%2 == 1 and X != Y:
      print((Y-1)*S + W)
    else:
      print(Y*S)
else:
  print((X+Y)*W)