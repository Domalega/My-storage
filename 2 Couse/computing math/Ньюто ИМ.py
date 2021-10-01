# q = (x - x0) / h
# y1 = y0,1 - y0,2

def Factarial(n):
    if n == 0:
        return 1
    return Factarial(n-1) * n

def Q(i, qNow):
  q = qNow
  if i == 0:
    return qNow
  for i in range(i):
    qNow *= (q + (i - 1))
  return qNow

def Delta(masY):
  masT = []
  for  j in range(1,len(masY) ):
    masT.append(masY[j] - masY[j - 1])
  masY = masT
  return masY

def Newton(x, masX, masY):
  for w in range(len(masX) - 1):
    masY = Delta(masY)
    print("y(delta " + str(w + 1) + ")=",masY)
    j = 0; p = masY[0]; q = 0
    for i in range(len(masY) - 1):
      p += masY[j] / Factarial(i + 1) * Q(i, q)
      j += 1
    print(p)
  print("last y delta = ", Delta(masY))


if __name__ == '__main__':
  x = 0; h = 1
  masX = [0, 1, 2, 3, 4]
  masY = [-1, 2, 13, 44, 107]
  Newton(x, masX, masY)
