# ver.1  1120ms / 83720KB
N = int(input())
A = list(map(int, input().split()))
topCard, bottomCard = [], []
for i in range(1,N+1):
  if A[-i] == 1:
    topCard.append(i)
  elif A[-i] == 2:
    topCard.insert(len(topCard)-1, i)
  else:
    bottomCard.append(i)
for element in reversed(topCard):
  print(element, end=' ')
for element in bottomCard:
  print(element, end=' ')


# ver.2  888ms / 125092KB
N = int(input())
A = list(map(int, input().split()))
topCard, bottomCard = [], []
for i in range(1,N+1):
  temp = A[-i]
  if temp == 1:
    topCard.append(str(i))
  elif temp == 2:
    topCard.insert(-1, str(i))
  else:
    bottomCard.append(str(i))
topCard.reverse()
print(' '.join(topCard + bottomCard))
