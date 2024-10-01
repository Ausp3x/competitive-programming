import random
from os import system

def list_rand(n, small, big):
    for _ in range(n):
        yield random.randint(small, big)

def gen_test_case(T, N, maxv):
    testcases = []
    for _ in range(T):
        K = random.randint(1, N)
        testcases.append([K, list(list_rand(N, 1, maxv))])

    nl = "\n"
    raw = f"""{T}
""" + "\n".join(map(lambda x: f"{N} {x[0]}\n{' '.join(map(str, x[1]))}", testcases))
    return raw
    
system("g++ -o brute brute.cpp")
system("g++ -o main main.cpp")
# system("mkdir tests")

for i in range(1000):
    with open("tests/test.in", "w+") as f:
        f.write(gen_test_case(3, 7, 4))
    
    system('./brute <"tests/test.in"> "tests/test-brute.out"')
    system('./main  <"tests/test.in"> "tests/test-main.out"')

    with open("tests/test-brute.out", "r+") as f1, open("tests/test-main.out", "r+") as f2:
        if(f1.read() != f2.read()):
            exit(1)