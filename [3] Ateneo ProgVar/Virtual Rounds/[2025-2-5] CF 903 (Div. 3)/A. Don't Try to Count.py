def solve():
    n, m = map(int, input().split())
    x = input()
    s = input()
    
    ans = 0
    while len(x) < 50:
        if s in x:
            print(ans)
            return
        
        x += x
        ans += 1
    
    print(-1)

    return

t = int(input())
for i in range(t):
    solve()