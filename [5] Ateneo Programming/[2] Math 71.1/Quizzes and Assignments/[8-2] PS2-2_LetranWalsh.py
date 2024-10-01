def compare(a, b):
    err = -1e9
    if abs(a - b) < err:
        return 0
    
    return (1 if a - b > 0 else -1)

c1, c2, r1, r2 = [float(x) for x in input().split()]
b = float(input())
K = int(input())

# -10 <= k - 2i <= 10
# -2i <= 10 - k  -> k / 2 - 5 <= i 
# -10 - k <= -2i -> i <= k / 2 + 5

n1, n2, P = 0, 0, 0
for k in range(0, K + 1):
    for i in range(max((k + 1) // 2 - 5, 0), min(k // 2 + 5, k) + 1):
        j = k - i

        cost = c1 * i + c2 * j
        gain = r1 * i + r2 * j
        
        if compare(cost, b) == 1:
            continue
        
        if compare(gain - cost, P) == 1:
            n1 = i
            n2 = j
            P = gain - cost
            
print(n1)
print(n2)
print(f'{P:.2f}')
            