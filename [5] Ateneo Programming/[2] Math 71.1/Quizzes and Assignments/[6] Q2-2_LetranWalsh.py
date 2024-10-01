n = int(input())
A = [int(a) for a in input().split()]

def solve():
    d = A[1] - A[0]
    for i in range(2, n):
        if A[i] - A[i - 1] != d:
            print('NO')
            return
        
    print('YES')
    print(f'initial term: {A[0]}')
    print(f'common difference: {d}')

    return
    
solve()