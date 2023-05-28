import random

n = int(input())
print(n)
for i in range(n):
	print(random.randrange(1, 11), end=" ")
print()
for i in range(n):
	print(random.randrange(1, 10000), end=" ")
