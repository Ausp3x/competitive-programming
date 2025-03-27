def solve():
    M, x, y, z = map(int, input().split())
    m = x ^ y ^ z
    
    ltrs = 'abcdefghijklmnopqrstuvwxyz_.?!-,'    
    ans = ''
    while M > 0:
        rem = m % 32
        
        ans += ltrs[rem] 
        
        m //= 32
        M -= 1
    
    print(ans[::-1])
    
    return
    
t = int(input())
while t > 0:
    solve()    
    t -= 1