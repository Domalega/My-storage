# 1)  1                         |
# 2)  (2.56−2)(2.56−3)(2.56−4)  |
# 3)  (1−2)( 1−3)(1−4)          |

def Lagrange(masX, masY, x):
  z = 0
  for j in range(0, len(masX)):
    numerator = 1; denominator = 1
    for i in range(0, len(masY)):
      if i == j:
        pass
      else:
        numerator *= (x - masX[i])
        denominator *= (masX[j] - masX[i])
    print("%.5f" % (masY[j] * numerator / denominator)," | ",str(j + 1) + "ое слогаемое")    
    z += masY[j] * numerator / denominator
  print(z) 

if __name__ == '__main__':
  x = 2.56 # число для которого применяем функцию Лагранжа
  masX = [1, 2, 3, 4]
  masY = [1.0000, 1.4142, 1.7321, 2.0000]

  Lagrange(masX, masY, x)
