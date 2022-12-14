import math
import matplotlib.pyplot as plt

x = [-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = []
equation_unsolved = []

highest_exponent = int(input("Highest exponent: "))
count = 0

while count <= highest_exponent:
    string = "_x^" + str(count) + "= "
    buffer = input(string)
    equation_unsolved.append(buffer)
    count += 1

for var in x:
    temp = 0
    exponent = 0;
    while exponent <= highest_exponent:
        buffer = abs(math.pow(var, exponent)) * int(equation_unsolved[exponent])
        temp += buffer
        exponent += 1
    print(temp)
    y.append(temp)

equation = ""
print_plus = False
while highest_exponent >= 0:
    if print_plus:
        equation += " + "
    equation += str(equation_unsolved[highest_exponent]) + "x^" + str(highest_exponent)
    print_plus = True
    highest_exponent -= 1
equation += " = 0"

print(equation)

plt.plot(x, y)
plt.xlabel(equation)
plt.show()