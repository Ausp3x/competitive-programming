def solve():
    n = int(input())
    A = [int(x) for x in input().split()]
    
    zer_cnts = [0 for _ in range(30)]
    one_cnts = [0 for _ in range(30)]
    for i in range(30):
        for j in range(n):
            if A[j] & (1 << i):
                one_cnts[i] += 1
            else:
                zer_cnts[i] += 1
    
    ans = 0
    for i in range(30):
        cur = 0
        if zer_cnts[i] >= 2 and one_cnts[i] >= 1:
            cur += zer_cnts[i] * (zer_cnts[i] - 1) * (one_cnts[i]) * (1 << i) * 3
        if one_cnts[i] >= 3:
            cur += one_cnts[i] * (one_cnts[i] - 1) * (one_cnts[i] - 2) * (1 << i)
    
        ans += cur
    
    print(ans)
                
    return

solve()