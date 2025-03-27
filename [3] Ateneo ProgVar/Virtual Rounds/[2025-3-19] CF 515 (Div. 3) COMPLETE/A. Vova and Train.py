def solve():
    L, v, l, r = map(int, input().split())
    
    if L < l:
        print(L // v)
        return
    
    r = min(r, L)
    
    print(L // v - (r // v - (l - 1) // v))
    
    return

t = int(input())
for _ in range(t):
    solve()