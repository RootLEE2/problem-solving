N = int(input())

for i in range(N):
  testCase = [0, 0]

  while True:
    line = input()

    if line == '':
      temp = round(100*testCase[1]/testCase[0], 1)
      if temp % 1 == 0:
        temp = int(temp)
      print("Efficiency ratio is " + str(temp)  + "%.")
      break
      
    temp = len(line)
    testCase[0] += temp
    testCase[1] += temp - line.count('#')