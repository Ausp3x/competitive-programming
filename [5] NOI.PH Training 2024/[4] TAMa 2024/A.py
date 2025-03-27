# https://cms.noi.ph/
# Ausp3x
# alpha-zone-meta

MOD = 998244353

def solve(N, k):
    R = [i for i in range(1, k + 1)]
    for i in range(k - 1, 0, -1):
        R.append(i)

    M = [i for i in range(1, 2 * k)]
    for i in range(2 * k - 1, N):
        m = 0
        for j in range(0, 2 * k - 1):
            m += R[j] * M[i - j - 1]
            m %= MOD
        
        M.append(m)

    ans = 0
    for m in M:
        ans += m
        ans %= MOD
        
    return ans

# print(solve(10, 3))
# print(solve(100000, 42))