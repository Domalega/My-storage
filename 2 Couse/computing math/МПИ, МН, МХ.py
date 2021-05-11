import math


e = 10 ** -8
x = int(input("Enter coefficient before x^2: "))
b = int(input("Enter coefficient before x: "))
c = int(input("Enter coefficient before: "))
a = x ** 2
D = b ** 2 - 4 * a * c
print("Discriminant =", D)
x1 = (-b + math.sqrt(D)) / 2 * x
print("x1 = ", x1)
x2 = (-b - math.sqrt(D)) / 2 * x
print("x2 = ", x2)
interval = max(x1, x2) # теперь необходимо взять правую границу и найти интервал
intb = math.ceil(interval)  # округляем в большую
inta = math.floor(interval)  # округляем в меньшую
print("Intrval [", inta, " ;", intb, "]", sep = "")


def Equation(koef, c, b):  
    return koef ** 2 + koef * b + c

def Derivative(koef):  
    return 2 * koef + b

def MPD(inta, intb):
    print("\nМетод половинного деления: \n")
    i = 1  # число шагов
    eps = 1
    while abs(eps) > e:
        C = (inta + intb) / 2
        eps = abs(intb-inta)/2
        f_a = Equation(inta, c, b)
        f_b = Equation(intb, c, b)
        f_c = Equation(C, c, b)
        Fac = f_a * f_c # f(a) * f(c)
        Fcb = f_b * f_c # f(c) * f(b)
        interval = min(Fac, Fcb)
        print("Step:", i, "\nValue:", interval)
        i += 1
        if Fac > Fcb:
            inta = C
            print("Intrval: [",inta, " ;", intb, "]", sep = "")
        else:
            intb = C
            print("[",inta, " ;", intb, "]", sep = "")
        print("Accuracy:", eps)
        print()

def MN(inta, intb):
    print("\nМетод Ньютона: \n")
    i = 0  # подчёт количества итераций,
    mas = []  # массив для сохранения xk
    eps = 1
    while abs(eps) > e:
        f_x = Equation(intb, c, b)
        F_x = Derivative(intb)
        xk = intb - f_x / F_x
        print("Step:", i + 1, "\nValue:", xk)
        mas.append(xk)  # добавление xk в конец массива
        i += 1
        intb = xk
        if i > 1:  # если кол-во xk > 1, считается eps
            eps = -mas[i-1] + mas[i-2]
    print("Accuracy:", eps)

def MH(inta, intb):
    print("\nМетод Хорд: \n")
    i = 0
    eps = 1
    mas = []  # массив для сохранения C
    while abs(eps) > e:
        f_b = Equation(intb, c, b)
        f_a = Equation(inta, c, b)
        C = (inta * f_b - intb * f_a)/(f_b - f_a)
        print("Step:", i + 1, "\nValue:", C)
        mas.append(C)  # добавление C в конец массива
        f_C = Equation(C, c, b)
        F1 = f_a * f_C
        F2 = f_C * f_b
        if F1 > F2:  # выбор отрицательного значения
            inta = C
        else:
            intb = C
        if i > 1:  # если кол-во C > 1, считается eps
            eps = mas[i] - mas[i-1]
        i += 1
    print("Accuracy:", eps)

MPD(inta, intb)
MN(inta, intb)
MH(inta, intb)
