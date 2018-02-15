import sys

n = int(input());

for i in range(n):
    expr = input();
    if expr == "P=NP":
        print("skipped")
        continue
    expr = expr.split("+")
    print(int(expr[0].strip()) + int(expr[1].strip()))
