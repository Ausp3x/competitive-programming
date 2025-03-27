def solve():
    n, r = map(int, input().split())
    A = list(map(int, input().split()))

    ans = 0
    vst = [False for _ in range(n)]
    for i in range(n):
        if vst[i]:
            continue
        
        has_heater = False
        for j in range(min(i + r - 1, n - 1), max(i - r, -1), -1):
            if not A[j]:
                continue
            
            ans += 1
            has_heater = True
            for k in range(max(j - r + 1, 0), min(j + r, n)):
                vst[k] = True
            
            break

        if not has_heater:
            print(-1)
            return
        
    print(ans)
   
    return

solve()