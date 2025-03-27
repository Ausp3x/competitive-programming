import math

n, k = 0, 0

def getL(i):
    return k * i + i * (i - 1) // 2

def getR(i):
    return k * (n - i) + n * (n - 1) // 2 - i * (i - 1) // 2

def getAbsDif(i):
    if i < 1 or i >= n:
        return 1000000000000000000000000000000000000
    
    return abs(getL(i) - getR(i))

t = int(input())
while t > 0:
    """
    at index i (1-indexed):
        L = ki + i(i - 1)/2
        R = k(n - i) + n(n - 1)/2 - i(i - 1)/2
    so
        L - R = k(2i - n) + i(i - 1) - n(n - 1)/2
                = 2ki - nk + i^2 - i - n^2/2 + n/2
    to get L - R >= 0:
        i^2 + (2k - 1)i - nk - (n^2 - n)/2 >= 0
    """
    
    n, k = map(int, input().split())

    a = 1
    b = 2 * k - 1
    c = -n * k - (n * n - n) // 2

    i = int((-b + math.sqrt(b * b - 4 * a * c)) / (2 * a))

    print(min(getAbsDif(i - 2), getAbsDif(i - 1), getAbsDif(i), getAbsDif(i + 1), getAbsDif(i + 2)))
    
    t -= 1