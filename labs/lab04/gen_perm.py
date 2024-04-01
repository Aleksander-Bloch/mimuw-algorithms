from random import shuffle

N = 20_000
seq = list(range(1, N + 1))

shuffle(seq)

for x in seq:
    print(x, end = ' ')
