import random
import subprocess

to_list = list()
n = int(input())
print(n)
k = n//2 + 1
k_sub = n - k
for i in range(k):
    to_list.append('R')
for i in range(k_sub):
    to_list.append('B')
random.shuffle(to_list)
f = open("c:\\Pig30nidaE\\ALGO\\sanghyol\\1week\\17615\\rand_case.txt", "w")
f.write(str(n))
f.write('\n')
for i in to_list:
    f.write(str(i))
print("c:\\Pig30nidaE\\ALGO\\sanghyol\\1week\\17615\\17615.exe < c:\\Pig30nidaE\\ALGO\\sanghyol\\1week\\17615\\rand_case.txt")
print("c:\\Pig30nidaE\\ALGO\\sanghyol\\1week\\17615\\ans.exe < c:\\Pig30nidaE\\ALGO\\sanghyol\\1week\\17615\\rand_case.txt")