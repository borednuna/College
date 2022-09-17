from prettytable import PrettyTable
import math

x = []
y = []
equation_unsolved = []

lower_x = int(input("Lower_x: "))
upper_x = int(input("Upper_x: "))
highest_exponent = int(input("Highest exponent: "))

count = 0
increment = (upper_x - lower_x) / 20

while lower_x <= upper_x:
    x.append(lower_x)
    lower_x += increment

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
    y.append(temp)

table = PrettyTable(["x", "f(x)", "x'", "f(x)'"])

count = 0
while count <= 10:
    table.add_row([x[count], y[count], x[count + 10], y[count + 10]])
    count += 1

print(table)
