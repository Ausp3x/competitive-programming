# https://cms.noi.ph/
# Ausp3x
# alpha-zone-meta

MOD = 10000019

def modPow(x, y):
    res = 1
    while y > 0:
        if y & 1:
            res *= x
            res %= MOD
            
        y >>= 1
        x *= x
        x %= MOD
        
    return res % MOD

def solve(n, m):
    fac = [max(i, 1) for i in range(n + 1)]
    for i in range(1, n + 1):
        fac[i] *= fac[i - 1]
        fac[i] %= MOD
        
    inv_fac = []
    for i in range(n + 1):
        inv_fac.append(modPow(fac[i], MOD - 2))
    
    ans = 0
    for i in range(m, n + 1):
        ans += fac[n] * inv_fac[i] % MOD * inv_fac[n - i] % MOD
        ans %= MOD
    
    return ans

# print(solve(10, 7))
# print(solve(60, 50))
# print(solve(10000000, 6666666))

def solve4():
    # print(202400769120730662 % MOD)
    # print(202400769120730662 // MOD % MOD)
    # print(202400769120730662 // (MOD * MOD) % MOD)
    # print(101200384561365331 % MOD)
    # print(101200384561365331 // MOD % MOD)
    # print(101200384561365331 // (MOD * MOD) % MOD)

    n, m = 202400769120730662, 101200384561365331
    
    fac = [max(i, 1) for i in range(10000100)]
    for i in range(1, 10000100):
        fac[i] *= fac[i - 1]
        fac[i] %= MOD
        
    inv_fac = []
    for i in range(10000100):
        inv_fac.append(modPow(fac[i], MOD - 2))
    
    ans = modPow(2, n - 1)
    
    for i in range(n // 2, m):
        num_l = [10000017, 10000018, 2023]
        den_l = [999999 + i - n // 2, 0, 1012]
        
        ctr = 1
        for j in range(3):
            ctr *= fac[num_l[j]] * inv_fac[den_l[j]] % MOD * inv_fac[num_l[j] - den_l[j]] % MOD
            ctr %= MOD
            
        if i == n:
            ctr *= inv_fac[2]
            ctr %= MOD
            
        ans -= ctr
        ans %= MOD
        
    return ans

print(solve4())

"""
#1-3:
pre-calc sum of nCm to nCn

#4: Lucas' Theorem
https://en.wikipedia.org/wiki/Lucas%27s_theorem
"""