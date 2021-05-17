from __future__ import print_function
import math


def maximum(Arr, n):
    max = 0
    for i in range(n):
        if abs(Arr[i]) > max:
            max = math.fabs(Arr[i])
    return max


def Zeidel():
    n = 3
    N = 0
    C = [0, 0, 0]
    c = [0, 0, 0]
    a = [[5, -1, 2], [-2, -10, 3], [1, 2, 5]]
    b = [3, -4, 12]

    print("Метод Зейделя")

    for i in range(n):
        for j in range(n + 1):
            if (j < n):
                print(a[i][j], end=" ")
            if (j == n):
                print("|", b[i], end=" ")
        print('\n')

    for i in range(n):
        d = a[i][i]
        for j in range(n):
            a[i][j] = a[i][j] / d
        b[i] = b[i] / d

    print('\n')
    for i in range(n):
        for j in range(n + 1):
            if (j < n):
                print(a[i][j], end=" ")
            if (j == n):
                print("|", b[i], end=" ")
        print('\n')

    print('\n')
    x = [0, 0, 0]
    for i in range(n):
        a[i][i] = a[i][i] - 1

    for i in range(n):
        for j in range(n + 1):
            if (j < n):
                print(a[i][j], end=" ")
            if (j == n):
                print("|", b[i], end=" "),
        print('\n')

    for i in range(n):
        for j in range(n):
            C[i] += math.fabs(a[i][j])

    N = math.log(0.0001 * (1 - maximum(C, n)) / maximum(b, n)) / math.log(
        maximum(C, n)) + 1

    for l in range(math.ceil(N - 1)):
      print("\nIteration:", l + 1, end=" ")
      for i in range(n):
        for j in range(n):
          if math.fabs(a[i][j]) != 0:
            c[i] = c[i] + (a[i][j] * x[j])
          x[i] = b[i] - c[i]
      for i in range(n):
        c[i] = 0
      print("\nX(", l + 1,")", sep = "")
      for i in range(n):
        print("\n", x[i], end=" ")

def MPI():
    n = 3
    N = 0
    C = [0, 0, 0]
    c = [0, 0, 0]
    a = [[5, -1, 2], [-2, -10, 3], [1, 2, 5]]
    b = [3, -4, 12]

    print("Метод МПИ")

    for i in range(n):
        for j in range(n + 1):
            if (j < n):
                print(a[i][j], end=" ")
            if (j == n):
                print("|", b[i], end=" ")
        print('\n')

    for i in range(n):
        d = a[i][i]
        for j in range(n):
            a[i][j] = a[i][j] / d
        b[i] = b[i] / d

    print('\n')
    for i in range(n):
        for j in range(n + 1):
            if (j < n):
                print(a[i][j], end=" ")
            if (j == n):
                print("|", b[i], end=" ")
        print('\n')

    print('\n')
    x = [0, 0, 0]
    for i in range(n):
        a[i][i] = a[i][i] - 1

    for i in range(n):
        for j in range(n + 1):
            if (j < n):
                print(a[i][j], end=" ")
            if (j == n):
                print("|", b[i], end=" "),
        print('\n')

    for i in range(n):
        for j in range(n):
            C[i] += math.fabs(a[i][j])

    N = math.log(0.0001 * (1 - maximum(C, n)) / maximum(b, n)) / math.log(
        maximum(C, n)) + 1

    for l in range(math.ceil(N - 1)):
      print("\nIteration:", l + 1, end=" ")
      for i in range(n):
        for j in range(n):
          if math.fabs(a[i][j]) != 0:
            c[i] = c[i] + (a[i][j] * x[j])
      for i in range(n):
        x[i] = b[i] - c[i]
        c[i] = 0
      print("\nX(", l + 1,")", sep = "")
      for i in range(n):
        print("\n", x[i], end=" ")


if __name__ == "__main__":
  Zeidel()
  print("\n\n")
  MPI()

