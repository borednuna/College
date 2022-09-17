from cProfile import label
from prettytable import PrettyTable
import matplotlib.pyplot as plt
import math

iterate = int(input("Iteration: "))
lower_x = int(input("Initial lower x: "))
upper_x = int(input("Initial upper x: "))

table = PrettyTable(["Iterasi", "x1", "x2", "x3", "f(x1)", "f(x2)", "f(x3)"])

highest_exponent = int(input("Highest exponent: "))
count = 0
equation_unsolved = []
x1_arr = []
x2_arr = []
x3_arr = []
y1_arr = []
y2_arr = []
y3_arr = []

while count <= highest_exponent:
    string = "_x^" + str(count) + "= "
    buffer = input(string)
    equation_unsolved.append(buffer)
    count += 1

iterate_counter = 1
while iterate_counter <= iterate:
    # for lower x
    temp = 0
    exponent = 0;
    while exponent <= highest_exponent:
        buffer = abs(math.pow(lower_x, exponent)) * int(equation_unsolved[exponent])
        temp += buffer
        exponent += 1
    y1 = temp

    # for upper x
    temp = 0
    exponent = 0;
    while exponent <= highest_exponent:
        buffer = abs(math.pow(upper_x, exponent)) * int(equation_unsolved[exponent])
        temp += buffer
        exponent += 1
    y2 = temp

    # for x3
    x3 = (lower_x + upper_x) / 2
    temp = 0
    exponent = 0;
    while exponent <= highest_exponent:
        buffer = abs(math.pow(x3, exponent)) * int(equation_unsolved[exponent])
        temp += buffer
        exponent += 1
    y3 = temp

    tuple = []
    tuple.append(iterate_counter)
    tuple.append(lower_x)
    tuple.append(upper_x)
    tuple.append(x3)
    tuple.append(y1)
    tuple.append(y2)
    tuple.append(y3)
    table.add_row(tuple)

    x1_arr.append(lower_x);
    y1_arr.append(y1)
    x2_arr.append(upper_x)
    y2_arr.append(y2)
    x3_arr.append(x3)
    y3_arr.append(y3)

    if (y1 * y2 < 0):
        lower_x = x3
    elif (y1 * y2 > 0):
        upper_x = x3
    iterate_counter += 1

print()
print(table)

plt.plot(x1_arr, y1_arr, label = "x1")
plt.plot(x2_arr, y2_arr, label = "x2")
plt.plot(x3_arr, y3_arr, label = "x3")
plt.show()
