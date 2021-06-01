def Function(i):
  return 1 / i

def Main():
  x = []
  y = []
  count = 0
  a = int(input("Interval\nLeft number: "))
  b = int(input("Right number: "))
  while a < b + 0.1:
    x.append(a)
    y.append(Function(a))
    a += 0.1
    count += 1

  for i in range(count):
    print(x[i], "\t", y[i])

 #numerical_integration
  answ = 0
  for i in range(count - 1):
    ans1 = (x[i + 1] - x[i])
    ans2 = (0.5 * y[i] + 0.5 * y[i + 1])
    answ += ans1 * ans2
  print(answ)

 #runge
  answ = 0
  for i in range(count - 2):
    ans1 = (x[i + 2] - x[i])
    tmp1 = 0.1 * y[i]
    tmp2 = 0.3 * y[i + 1]
    tmp3 = 0.1 * y[i + 2]
    ans2 = tmp1 + tmp2 + tmp3
    answ += ans1 * ans2
  print(answ)

if __name__ == "__main__":
  Main()
