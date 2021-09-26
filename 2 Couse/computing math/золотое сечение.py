def Function(x):
  return(x * x - 6 * x) # функция которая вычисляется abs(b - a) / 2 > eps

def Lambda(b, a, ratio):
  return (a + ratio * (b - a)) # формула одной итерации 

def GoldenRatio(b, a, ratio1, ratio2, eps):
  i = 0
  while(abs(b - a) / 2 > eps):
    print(i + 1, "step")
    if (Function(Lambda(b, a, ratio1)) > Function(Lambda(b, a, ratio2))): # сравнение значений функций от 2ух лямбд
      a = Lambda(b, a, ratio1)
    else:
      b = Lambda(b, a, ratio2)
    i += 1
    print("[" + str("%f5" % a) + ";  " + str("%f5" % b) + "]")
  print("f(x) = ", Function((a + b ) / 2)) 


if __name__ == '__main__':
  a = 0; b = 5; eps = 10 ** (-4)
  ratio1 = 0.382; ratio2 = 0.68
  GoldenRatio(b, a, ratio1, ratio2, eps)
