def FunctionXY(x, y): # обычная функция 
  return(2 * x - y)

def FunctionYi(y, xy, h): # вычисление y i-ый
  return(y + xy * h)

def Euler(x, y, h): # вычисление ДУ методом Эйлера 
  for i in range(3):
    xy = FunctionXY(x, y)
    y = FunctionYi(y, xy, h)
    x += 0.2
    print("Step", i + 1)
    print("f(xi, yi) = %.3f" %xy ,"\tyi = %.3f" % y)
    print()

def FunctionYiHalf(y, xy, h): # вычисление половинного y i-ый
  return(y + h / 2 * xy)

def FunctionFHalf(y, xy, h): # вычисление функции от половинного y 
  return(y + xy * h / 2)

def RungeKutta(x, y, h): # вычисление ДУ методом  Рунге-Кутта
  half = 0.5
  for i in range(3):
    xy = FunctionXY(x, y)
    yHalf = FunctionYiHalf(y, xy, h)
    fHalf = FunctionXY(x + h / 2,yHalf)
    y = FunctionYi(y, fHalf, h)
    x += 0.2
    print("Step", i + 1)
    print("f(xi, yi) = %.3f" % xy,"\ty" + str(half) + " =", "%.3f" % yHalf)
    print("f(x + h/2; y"+ str(half) + ") =%.3f" %  fHalf ,"y =", "%.3f" % y)
    print()
    half += 1


if __name__ == '__main__':
  x = 1; y = 3; h = 0.2

  print("\tdifferential equation by Euler\t\n")
  Euler(x, y, h)

  print("\n\tdifferential equation by Runge-Kutta\t\n")
  RungeKutta(x, y, h)
