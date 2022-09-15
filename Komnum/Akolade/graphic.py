import math
import matplotlib.pyplot as plt

x = [-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = []

equation_unsolved = []
buffer = input("x = ");
equation_unsolved.append(buffer);
buffer = input("x^2 = ");
equation_unsolved.append(buffer);
buffer = input("x^3 = ");
equation_unsolved.append(buffer);
buffer = input("x^4 = ");
equation_unsolved.append(buffer);
buffer = input("x^5 = ");
equation_unsolved.append(buffer);

for var in x:
    temp = 0
    exponent = 0;
    while exponent <= 4:
        buffer = abs(math.pow(var, exponent)) * int(equation_unsolved[exponent])
        temp += buffer
        exponent += 1
    print(temp)
    y.append(temp)

equation = str(equation_unsolved[4]) + "x^5 + " + str(equation_unsolved[3]) + "x^4 + " + str(equation_unsolved[2]) + "x^3 + " + str(equation_unsolved[1]) + "x^2 + " + str(equation_unsolved[0]) + "x = 0"
plt.plot(x, y)
plt.xlabel(equation)
plt.show()