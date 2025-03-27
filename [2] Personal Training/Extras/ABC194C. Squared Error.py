def solve():
    n = int(input())
    A = [int(a) for a in input().split()]

    A_sq_sum = 0
    for a in A:
        A_sq_sum += a * a
    
    ans = A_sq_sum * (n - 1)
    
    A_suf = [A[i] for i in range(n)]
    for i in range(n - 2, -1, -1):
        A_suf[i] += A_suf[i + 1]
        
    for i in range(0, n - 1):
        ans -= 2 * A[i] * A_suf[i + 1]
        
    print(ans)
    
    return

solve()