from os import system
from difflib import Differ 

with open('inp.txt', 'w+') as f:  
    f.write('100000\n')
    for i in range(900000, 1000000):
        f.write(f'{5} {str(i % 100000).zfill(5)}\n')

system('g++ -o brute D.cpp')
system('g++ -o main  D_Mathematical_Problem.cpp')
system('brute.exe < inp.txt > out-brute.txt')
system('main.exe  < inp.txt > out-main.txt')

with open('out-brute.txt', 'r+') as f1, open('out-main.txt', 'r+') as f2:
    if (f1.read() != f2.read()):
        print('FUCK') 
        exit(1)
print('EPIC')