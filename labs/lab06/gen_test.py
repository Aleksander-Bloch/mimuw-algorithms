import random

M = 1000

print(M)

for i in range(M):
    op = random.choice(['i', 'g'])
    if i == 0:
        op = 'i'
    j = random.randint(0, 1000)
    if op == 'g':
        print(f"{op} {j}")
    else:
        x = random.randint(0, 100)
        k = random.randint(1, 100)
        print(f"{op} {j} {x} {k}")
