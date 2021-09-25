import math


def doubleCounting(arrayX, arrayY, h):
  P = 0
  for i in range(0, N):
    if arrayX[i + 2] == 1:
      break
    P += (arrayX[i + 1] - arrayX[i]) * ((1.0 / 2.0) * arrayY[i] + (1.0 / 2.0) * arrayY[i + 1])
  return P


if __name__ == '__main__':
  N = 10000
  PI = 3.14159265358979323846
  
  h = 0.1
  up = 2.0
  down = 1
  eps = 10 ** -8
  irel = 0
  arrayX = []
  arrayY = []
  xNow = []

  for i in range(0, N):
    arrayX.append(1)
    arrayY.append(0)

  for i in range(0, N - 1):
    xNow.append(1.44) # i^3 = 3i^2

  # Вычисление интеграла с шагом h 

  print("x     |         y")
  for i in range(0, N):
    arrayX[i] = arrayX[0] + i * h
    arrayY[i] = 1 / arrayX[i]
    if arrayX[i] > up:
      break
    print("%.2f" % arrayX[i] , " | ", "%.6f" % arrayY[i])
  
  irel = math.log(up) - math.log(down)

  print("\neps = ", eps)
  print("irel = ", "%.6f" % irel)
  print()
  print("i = ", "%.6f" % doubleCounting(arrayX, arrayY, h))
  
  # Вычисление интеграла с шагом h / 2

  for i in range(0, N):
    h = h / 2
    for i in range(0, N):
      arrayX[i] = arrayX[0] + i * h
      arrayY[i] = 1 / arrayX[i]
      if (arrayX[i] > up):
        break
    print("I = ", doubleCounting(arrayX, arrayY, h), "h = ", h)
    if (doubleCounting(arrayX, arrayY, h) - irel) < eps:
      print("I_last", doubleCounting(arrayX, arrayY, h))
      break
