# N, K = map(int, input().split())

for N in range(1, 101):
    K = 2
    
    s = ''
    for i in range(1, N + 1):
        if i <= K:
            s += '0'
            continue
        
        j = 1
        while j * K <= i - 1:
            # print(i, s[i - j * K - 1:], K * s[i - j - 1:])
            
            if s[i - j * K - 1:] == K * s[i - j - 1:]:
                s += '1'
                break 
            
            j += 1
            
        if len(s) < i:
            s += '0'

    print(N, s.count('1'))
    print(f'\'{s}\'')