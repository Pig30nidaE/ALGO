from random import randint
n = int(input())
print(n)
for i in range(1, n + 1):
    for j in range(i):
        if (j != i - 1):
            print(randint(1, 10000), end=" ")
        else:
            print(9999, end="")
    print()