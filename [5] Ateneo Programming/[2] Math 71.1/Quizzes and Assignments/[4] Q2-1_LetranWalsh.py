n = int(input())
A = list(map(int, input().split()))

for i in range(1, n):
    d = A[i] - A[i - 1]
    
    if d > 0:
        print('+', end = '')
    
    print(d, end = ' ' if i < n - 1 else '')