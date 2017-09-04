dice = input();
d1, d2 = (int(i) for i in dice.split());
prob = [];
for i in range(0, d1+d2):
    prob.append(0);
for i in range(0, d1):
    for j in range(0, d2):
        temp = i + j;
        prob[temp] += 1;
maximum = 0;
for i in range(0, d1+d2):
    if prob[i] > maximum:
        maximum = prob[i];
for i in range(0, d1+d2):
    if prob[i] == maximum:
        print(i + 2);
