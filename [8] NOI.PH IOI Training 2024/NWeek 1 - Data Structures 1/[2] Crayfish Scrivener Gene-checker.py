import random
from os import system

opt = ['T', 'U', 'P']
alp = 'abcdefghijklmnopqrstuvwxyz'
def generator(t):
    inp = str(t) + '\n'
    history = ['']
    for i in range(t):
        c = random.choice(opt)
        if c == 'T':
            x = random.choice(alp)
            history.append(history[-1] + x)
            inp += str(c) + ' ' + str(x) + '\n'
        elif c == 'U':
            if len(history) > 1:
                x = random.randint(1, len(history) - 1)
                history.append(history[-x - 1])
                inp += str(c) + ' ' + str(x) + '\n'
            # print()
        elif c == 'P':
            if len(history[-1]) > 0:
                inp += str(c) + ' ' + str(random.randint(0, len(history[-1]) - 1)) + '\n'
            # print()

    return inp

system('g++ -o brute brute.cpp')
system('g++ -o main main.cpp')

for i in range(100000):
    with open('inp.txt', 'w+') as f:
        f.write(generator(30))
    
    system('brute.exe < inp.txt > out-brute.txt')
    system('main.exe  < inp.txt > out-main.txt')

    with open('out-brute.txt', 'r+') as f1, open('out-main.txt', 'r+') as f2:
        if (f1.read() != f2.read()):
            print(i) 
            exit(1)