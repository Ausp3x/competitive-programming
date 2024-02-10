import math
import itertools

# QUESTION A
# lucas = [2, 1]
# parity = [0, 1]
# m = 998244353

# cur, ans = 0, 4
# for _ in range(2, 1002023):
#     lucas[cur] = lucas[0] + lucas[1]
#     lucas[cur] %= m
#     parity[cur] = parity[0] ^ parity[1]

#     if parity[cur] == 0:
#         ans += lucas[cur] * lucas[cur]
#         ans %= m
    
#     cur ^= 1

# print(ans)

# n = 10 ** 15 + 2999
# m = 10 ** 18 + 2999

# # lucas = [2, 1]
# # ans = 4
# # for i in range(2, n):
# #     lucas.append(lucas[-1] + lucas[-2])
    
# #     if lucas[-1] % 2 == 0:
# #         ans += lucas[-1] * lucas[-1]

# # print(ans % m)

# I = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
# T = [[17, 17, -1, 1], [1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, 1]]
# A = [344, 20, 4, -64]

# # matrix size = 4, exp >= 0

# def mtx_exp(mtx, exp):
#     if exp == 0:
#         return I
#     if exp == 1:
#         return T

#     M = mtx_exp(mtx, exp // 2)
#     M_new = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
#     for i in range(4):
#         for j in range(4):
#             for k in range(4):
#                 M_new[i][j] += M[i][k] * M[k][j]
#                 M_new[i][j] %= m

#     if exp % 2 != 0:
#         M_new_new = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
#         for i in range(4):
#             for j in range(4):
#                 for k in range(4):
#                     M_new_new[i][j] += M_new[i][k] * T[k][j]
#                     M_new[i][j] %= m
#         return M_new_new

#     return M_new

# F = mtx_exp(T, (n - 1) // 3 - 2)

# ans = 0
# for j in range(4):
#     ans += F[0][j] * A[j]
#     ans %= m

# print(ans)



# QUESTION B
# N = 1
# m = 998244353

# for n in range(55):
#     fibonacci = [0, 1]
#     for _ in range(2, n + 2):
#         fibonacci.append(fibonacci[-2] + fibonacci[-1])
#         fibonacci[-1] %= m

#     fib_idxs = {1: 0}
#     for i in range(2, n + 2):
#         for x, y in fib_idxs.items():
#             fib_idxs[math.gcd(x, i)] += fib_idxs[x]
#             fib_idxs[math.gcd(x, i)] %= m 
#         fib_idxs[i] = 1

#     ans = 0
#     for x, y in fib_idxs.items():
#         ans += fibonacci[x] * fib_idxs[x]
#         ans %= m

#     # print(fib_idxs)
#     print(n, ans)



# QUESTION C
# n = 5 ** 5

# ans = 0
# for a in range(-n, n + 1):
#     for b in range(-n, n + 1):
#         # for c in range(-n, n + 1):
#         #     if a == 0 or a + 2 * c == 0 or b == 0 or 2 * a - b + 3 * c == 0:
#         #         continue

#         #     if 4 * (a + c) * b * (2 * a - b + 3 * c) == a * (a + 2 * c) * (6 * a - 2 * b + 9 * c):
#         #         ans += 1

#         if a == 0 or b == 0:
#             continue

#         c1, c2 = None, None
#         if (2 * b - 3 * a) % 6 == 0:
#             if abs((2 * b - 3 * a) // 6) <= n:
#                 c1 = (2 * b - 3 * a) // 6
        
#         if 3 * a != 2 * b:
#             if 2 * (a * a - a * b) % (2 * b - 3 * a) == 0:
#                 if abs(2 * (a * a - a * b) // (2 * b - 3 * a)) <= n:
#                     c2 = 2 * (a * a - a * b) // (2 * b - 3 * a)
        
#         if c1 != None:
#             if a + 2 * c1 == 0 or 2 * a - b + 3 * c1 == 0:
#                 c1 = None

#         if c2 != None:
#             if a + 2 * c2 == 0 or 2 * a - b + 3 * c2 == 0:
#                 c2 = None

#         if c1 == None and c2 == None:
#             continue

#         ans += c1 != None
#         ans += c2 != None
#         ans -= c1 == c2

# print(ans)



# QUESTION D
# r, c = 2, 8
# m = 998244353

# single_row = [1, 1]
# for i in range(2, c + 1):
#     single_row.append(single_row[-1] + single_row[-2])

# print(single_row)

# def modAdd(a, b):
#     return (a + b) % m

# double_row = [[-1 for i in range(c + 1)] for j in range(c + 1)]
# double_row[0][0] = 1
# def dp(r1, r2):
#     if r1 < 0 or r2 < 0:
#         return 0
    
#     if double_row[r1][r2] != -1:
#         return double_row[r1][r2]
#     double_row[r1][r2] = 0

#     if r1 == r2:
#         if r1 >= 1:
#             double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - 1] * single_row[r1 - 1])
#             for i in range(1, r1):
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i - 1] * single_row[r1 - i] * dp(i, i - 1))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i] * single_row[r1 - i - 1] * dp(i - 1, i))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i - 1] * single_row[r1 - i - 1] * dp(i, i))
            
#         if r1 >= 2:
#             double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - 2] * single_row[r1 - 1])
#             double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - 1] * single_row[r1 - 2])
#             double_row[r1][r1] = modAdd(double_row[r1][r1], 2 * single_row[r1 - 2] * single_row[r1 - 2])
#             for i in range(1, r1 - 1):
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i - 2] * single_row[r1 - i] * dp(i, i - 1))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i - 1] * single_row[r1 - i - 1] * dp(i - 1, i))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i - 2] * single_row[r1 - i - 1] * dp(i, i))
                
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i - 1] * single_row[r1 - i - 1] * dp(i, i - 1))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i] * single_row[r1 - i - 2] * dp(i - 1, i))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], single_row[r1 - i - 1] * single_row[r1 - i - 2] * dp(i, i))
                
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], 2 * single_row[r1 - i - 2] * single_row[r1 - i - 1] * dp(i, i - 1))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], 2 * single_row[r1 - i - 1] * single_row[r1 - i - 2] * dp(i - 1, i))
#                 double_row[r1][r1] = modAdd(double_row[r1][r1], 2 * single_row[r1 - i - 2] * single_row[r1 - i - 2] * dp(i, i))
#             double_row[r1][r1] = modAdd(double_row[r1][r1], dp(r1 - 2, r1 - 1))
#             double_row[r1][r1] = modAdd(double_row[r1][r1], dp(r1 - 1, r1 - 2))
                
#     if r1 + 1 == r2: 
#         if r1 >= 1:
#             double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r1 - 1] * single_row[r2 - 2])
#             for i in range(1, r1):
#                 double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r1 - i - 1] * single_row[r1 - i] * dp(i, i - 1))
#                 double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r1 - i] * single_row[r1 - i - 1] * dp(i - 1, i))
#                 double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r1 - i - 1] * single_row[r1 - i - 1] * dp(i, i))

#     if r1 == r2 + 1: 
#         if r2 >= 1:
#             double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r1 - 2] * single_row[r2 - 1])
#             for i in range(1, r2):
#                 double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r2 - i - 1] * single_row[r2 - i] * dp(i, i - 1))
#                 double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r2 - i] * single_row[r2 - i - 1] * dp(i - 1, i))
#                 double_row[r1][r2] = modAdd(double_row[r1][r2], single_row[r2 - i - 1] * single_row[r2 - i - 1] * dp(i, i))

#     return double_row[r1][r2]

# dp(c, c)

# for line in double_row:
#     print(line)

# ans = 0
# ans = modAdd(ans, single_row[c] * single_row[c])
# for i in range(1, c + 1):
#     ans = modAdd(ans, single_row[c - i] * single_row[c - i + 1] * dp(i, i - 1))
#     ans = modAdd(ans, single_row[c - i + 1] * single_row[c - i] * dp(i - 1, i))
#     ans = modAdd(ans, single_row[c - i] * single_row[c - i] * dp(i, i))

# print(ans)



# QUESTION E
# n = 12
# m = 998244353

# grid = [[pow(1669661, 2023 * i * j, m) for j in range(1, n + 1)] for i in range(1, n + 1)]

# for line in grid:
#     print(line)
# print()

# ans = 0
# for i in range(1, n + 1):
#     for j in range(i, n + 1):
#         cur = grid[i - 1][j - 1]
#         vals = [[-1 for j in range(n + 2)] for i in range(n + 2)]
#         vals[i][j] = cur

#         not_yet_done = True
#         while not_yet_done:
#             not_yet_done = False
#             for k in range(1, n + 1):
#                 for l in range(1, n + 1):
#                     if vals[k][l] == -1:
#                         not_yet_done = True
#                         break            
#                 if not_yet_done:
#                     break

#             maintain = False
#             new_cur = 0
#             for k in range(1, n + 1):
#                 for l in range(1, n + 1):
#                     if vals[k][l] != -1:
#                         continue

#                     if vals[k - 1][l] != -1 or vals[k][l - 1] != -1 or vals[k][l + 1] != -1 or vals[k + 1][l] != -1:
#                         if grid[k - 1][l - 1] >= cur:
#                             vals[k][l] = cur
#                             maintain = True
#                         else:
#                             new_cur = max(new_cur, grid[k - 1][l - 1])
#             if not maintain:
#                 cur = new_cur
        
#         # for line in vals:
#         #     print(line)
#         # print()

#         for k in range(1, n + 1):
#             for l in range(1, n + 1):
#                 if k == i and l == j:
#                     continue
                
#                 ans += vals[k][l]
#                 if i != j:
#                     ans += vals[k][l]
#                 ans %= m

# print(ans)



# QUESTION F
# r, c = 64000000, 10000000000000000
# m = 998244353

# if r > c:
#     r, c = c, r

# print(r, c)

# ans = 0
# cnts = {}
# for i in range(1 << (r * c)):
#     row_sum = [0 for _ in range(r)]
#     col_sum = [0 for _ in range(c)]
#     for j in range(r * c):
#         row_sum[j // c] += (i & (1 << j)) > 0
#         col_sum[j % c] += (i & (1 << j)) > 0

#     row_odd = 0
#     for j in range(r):
#         row_odd += row_sum[j] % 2 != 0
        
#     col_odd = 0
#     for j in range(c):
#         col_odd += col_sum[j] % 2 != 0

#     ans += pow(max(row_odd, col_odd), 3, m)
#     ans %= m

# print(ans)

# facs = [1]
# inv_facs = [pow(1, m - 2, m)]
# for i in range(1, c + 1000):
#     facs.append(facs[-1] * i)
#     inv_facs.append(pow(facs[i], m - 2, m))

# def choose(x, y):
#     return facs[x] * inv_facs[y] * inv_facs[x - y] % m

# ans = 0
# for i in range(0, r + 1):
#     for j in range(i % 2, c + 1, 2):
#         cur = (max(i, j) ** 3) * choose(r, i) * choose(c, j) * pow(2, (r - 1) * (c - 1), m)    
#         ans += cur
#         ans %= m

# print(ans)

# special = {}
# for i in range(0, r + 1, 2):
#     for j in range(0, c + 1, 2):
#         # print(choose(r, i) * choose(c, j), end = " ")
        
#         if special.get(max(i, j)) == None:
#             special[max(i, j)] = choose(r, i) * choose(c, j)
#         else:
#             special[max(i, j)] += choose(r, i) * choose(c, j)
#     # print()

# special2 = {0: 1}
# for i in range(2, r + 1, 2):
#     special[i] += special[i - 2]
#     special2[i] = math.isqrt(special[i])

# print(special)
# print(special2)

# ans = 0
# choose_sum = 0
# for i in range(0, r + 1, 2):
#     choose_sum += choose(r, i)
#     choose_sum %= m
    
#     i_cubed = i * i * i % m 
#     ans += i_cubed * choose(r, i) * (2 * choose_sum - choose(r, i))
#     ans %= m
    
#     # print(i, choose_sum, choose(r, i) * (2 * choose_sum - choose(r, i)))

# choose_sum = 0
# for i in range(1, r + 1, 2):
#     choose_sum += choose(r, i)
#     choose_sum %= m
    
#     i_cubed = i * i * i % m 
#     ans += i_cubed * choose(r, i) * (2 * choose_sum - choose(r, i))
#     ans %= m

#     # print(i, choose_sum, choose(r, i) * (2 * choose_sum - choose(r, i)))

# r2 = r // 2 + 1
# ans *= pow(2, (r - 1) * (r - 1), m)
# ans %= m

# print(ans)

# ans = pow(2, r + c - 4, m) * c * c * (c + 3)
# ans %= m

# cur = pow(2, r - 4, m) * r * r * (r + 3)
# R_sum = pow(2, r - 1, m)
# R, C = 1, 1
# for i in range(0, r + 1, 2):
#     cur -= (i * i * i * R) % m 
#     cur %= m
#     R_sum -= R
#     R_sum %= m

#     ans += C * (cur - i * i * i * R_sum) 
#     ans %= m

#     R *= r - i
#     R %= m
#     R *= r - i - 1
#     R %= m
#     R *= pow(i + 1, m - 2, m)
#     R %= m
#     R *= pow(i + 2, m - 2, m)
#     R %= m

#     C *= c - i
#     C %= m
#     C *= c - i - 1
#     C %= m
#     C *= pow(i + 1, m - 2, m)
#     C %= m
#     C *= pow(i + 2, m - 2, m)
#     C %= m

# cur = pow(2, r - 4, m) * r * r * (r + 3)
# R_sum = pow(2, r - 1, m)
# R, C = r, c
# for i in range(1, r + 1, 2):
#     cur -= (i * i * i * R) % m 
#     cur %= m
#     R_sum -= R
#     R_sum %= m

#     ans += C * (cur - i * i * i * R_sum) 
#     ans %= m

#     R *= r - i
#     R %= m
#     R *= r - i - 1
#     R %= m
#     R *= pow(i + 1, m - 2, m)
#     R %= m
#     R *= pow(i + 2, m - 2, m)
#     R %= m

#     C *= c - i
#     C %= m
#     C *= c - i - 1
#     C %= m
#     C *= pow(i + 1, m - 2, m)
#     C %= m
#     C *= pow(i + 2, m - 2, m)
#     C %= m

# ans *= pow(2, (r - 1) * (c - 1), m)
# ans %= m

# print(ans)

# for i in range(0, 31, 2):
#     cur = 0
#     for j in range(0, i + 1, 2):
#         cur += j * j * j * choose(i, j)

#     print(i, cur, pow(2, i - 4, m) * i * i * (i + 3))

# for i in range(1, 32, 2):
#     cur = 0
#     for j in range(1, i + 1, 2):
#         cur += j * j * j * choose(i, j)

#     print(i, cur, pow(2, i - 4, m) * i * i * (i + 3))



# QUESTION G
# n, b = 100, 4000
# MOD = 998244353

# primes = []
# idxs = {}
# for i in range(2, b):
#     is_prime = True
#     for p in primes:
#         if i % p == 0:
#             is_prime = False
#             break
    
#     if is_prime:
#         primes.append(i)
#         idxs[i] = len(primes) - 1

# print(primes)
# print(idxs)

# mM_cnts = {}
# for i in range(2, b):
#     m = b
#     M = 1
#     for p in primes:
#         if i % p == 0:
#             m = min(m, p)
#             M = max(M, p)

#     if mM_cnts.get(m) == None:
#         mM_cnts[m] = {M: 1}
#     elif mM_cnts[m].get(M) == None:
#         mM_cnts[m][M] = 1
#     else:
#         mM_cnts[m][M] += 1

# print(mM_cnts)

# facs = [1]
# inv_facs = [pow(1, MOD - 2, MOD)]
# for i in range(1, b):
#     facs.append(facs[-1] * i)
#     inv_facs.append(pow(facs[i], MOD - 2, MOD))

# def choose(x, y):
#     return facs[x] * inv_facs[y] * inv_facs[x - y] % MOD

# p_len = len(primes)
# memo = [[[-1 for w in range(p_len)] for v in range(p_len)] for u in range(n + 1)]
# def amazing_sequences(k, p_idx, P_idx):
#     if k == 0:
#         return 1
#     if P_idx > p_len - k:
#         return 0
#     if memo[k][p_idx][P_idx] != -1:
#         return memo[k][p_idx][P_idx]

#     res = 0
#     for i in range(p_idx + 1, p_len):
#         for new_P, cnt in mM_cnts[primes[i]].items():
#             if P_idx == -1 or new_P > primes[P_idx]:
#                 res += cnt * amazing_sequences(k - 1, i, idxs[new_P])
#                 res %= MOD

#     memo[k][p_idx][P_idx] = res
#     return res

# ans = amazing_sequences(n, -1, -1)
# print(ans)



# QUESTION H
# n, w, k = 200, 500, 300
# m = 998244353

# facs = [1]
# inv_facs = [pow(1, m - 2, m)]
# for i in range(1, w + 1):
#     facs.append(facs[-1] * i)
#     inv_facs.append(pow(facs[i], m - 2, m))

# def choose(x, y):
#     return facs[x] * inv_facs[y] * inv_facs[x - y] % m

# def inv_choose(x, y):
#     return inv_facs[x] * facs[y] * facs[x - y] % m

# # L = lowest number chosen, number of L, (cnt, sum)
# dp = [[[[0, 0], [0, 0]] for i in range(n + 1)] for j in range(k + 1)]
# for i in range(1, k + 1):
#     dp[i][1][1][0] = 1
#     dp[i][1][1][1] = i

# for i in range(1, n):
#     for j in range(1, k + 1):
#         for l in range(1, n + 1):
#             dp[j][l][(i + 1) % 2][0] = 0
#             dp[j][l][(i + 1) % 2][1] = 0

#     for j in range(1, k + 1):
#         for l in range(1, n):
#             for o in range(1, k + 1):
#                 nxt = (i + 1) % 2
#                 if o < j:
#                     dp[o][1][nxt][0] += dp[j][l][i % 2][0]
#                     dp[o][1][nxt][1] += dp[j][l][i % 2][1] + dp[j][l][i % 2][0] * o
#                     dp[o][1][nxt][0] %= m
#                     dp[o][1][nxt][1] %= m
#                 elif o == j:
#                     dp[j][l + 1][nxt][0] += dp[j][l][i % 2][0]
#                     dp[j][l + 1][nxt][1] += dp[j][l][i % 2][1] + dp[j][l][i % 2][0] * o
#                     dp[j][l + 1][nxt][0] %= m
#                     dp[j][l + 1][nxt][1] %= m
#                 else:
#                     dp[j][l][nxt][0] += dp[j][l][i % 2][0]
#                     dp[j][l][nxt][1] += dp[j][l][i % 2][1] + dp[j][l][i % 2][0] * o
#                     dp[j][l][nxt][0] %= m
#                     dp[j][l][nxt][1] %= m
#     print(i)

# # for line in dp:
# #     print(line)

# # k is number of non-chosen L
# ans = 0
# for j in range(1, n + 1):
#     cur = dp[1][j][n % 2][1] * inv_choose(n, j) * choose(w, n - j)
#     cur %= m

#     # print(1, j, w - j, cur)

#     ans += cur
#     ans %= m

# for i in range(2, k + 1):
#     for j in range(1, n + 1):
#         for l in range(0, w - n + 1):
#             cur = dp[i][j][n % 2][1] * inv_choose(n, j) * choose(n + l, n - j)
#             cur %= m
#             cur *= choose(w, n + l) * pow(i - 1, w - n - l, m)
#             cur %= m

#             # print(i, j, l, cur)

#             ans += cur
#             ans %= m

# # print(ans)

# div = pow(pow(k, w, m), m - 2, m)
# print(ans * div % m)

# # ans = 0
# # for i in range(1, 4):
# #     for j in range(1, 4):
# #         for l in range(1, 4):
# #             for o in range(1, 4):
# #                 arr = [i, j, l, o]
# #                 arr.sort(reverse=True)
# #                 print(arr)
# #                 ans += arr[0] + arr[1] + arr[2]

# # print(ans)



# QUESTION I
# n = 27000
# m = 998244353

# L = []
# for i in range(1, n + 1):
#     if i * i > n:
#         break

#     if n % i == 0:
#         L.append([i, n // i])

# # print(L)

# # k = 5
# # ans = 0
# # for p in itertools.permutations([i // 2 + 1 for i in range(0, 2 * k)]):
# #     chk = True
# #     for i in range(0, 2 * k, 2):
# #         if p[i] == p[i + 1]:
# #             chk = False
# #             break
    
# #     ans += chk

# # ans //= pow(2, 2 * k, m)
# # print(ans)

# facs = [1]
# inv_facs = [pow(1, m - 2, m)]
# for i in range(1, n + 1):
#     facs.append(facs[-1] * i)
#     inv_facs.append(pow(facs[i], m - 2, m))

# # print(facs)

# def choose(x, y):
#     return facs[x] * inv_facs[y] * inv_facs[x - y] % m

# ans = 0
# for r, c in L:
#     A = [1, 0, 1]
#     for i in range(3, r + 1):
#         # A.append((i * ((i - 1) ** 2) // 2) * ((2 * i - 3) * A[-2] + (i - 2) ** 2 * A[-3]))
#         A.append(pow(2, m - 2, m) * i * pow(i - 1, 2, m) * ((2 * i - 3) * A[-2] + pow(i - 2, 2, m) * A[-3]))
#         A[-1] %= m

#     # print(A)

#     cur = 0
#     for i in range(0, r + 1):
#         cur += choose(r, i) * choose(c, i) * facs[i]
#         cur %= m

#     for i in range(2, r + 1):
#         cur += choose(r, i) * choose(c, i) * A[i]
#         cur %= m

#     ans += cur
#     if r != c:
#         ans += cur
#     ans %= m

# print(ans)



# QUESTION J
# Y = 365
# n, C = 4 * Y, 10
# m = 9982443520000001

# days = {1: 31, 
#         32: 31, 
#         60: 28, 
#         91: 31, 
#         121: 30, 
#         152: 31, 
#         182: 30, 
#         213: 31, 
#         244: 31, 
#         274: 30, 
#         305: 31, 
#         335: 30}

# print(days)

# current day, activity done first day of current month, activity done today
# ans = 0
# for c in range(1, C + 1):
#     dp = [[[[0 for l in range(c)] for k in range(c)] for j in range(c)] for i in range(n + 1)]
#     for j in range(c):
#         dp[1][j][j][j] = 1

#     for i in range(1, n):
#         for o in range(c): # first activity of cycle
#             for j in range(c): # first day of current month activity
#                 for k in range(c): # today activity
#                     for l in range(c): # next day activity
#                         if l == k:
#                             continue
                        
#                         if days.get((i + 1) % 365) == None:
#                             dp[i + 1][o][j][l] += dp[i][o][j][k]
#                             dp[i + 1][o][j][l] %= m
#                         elif l != j:
#                             dp[i + 1][o][l][l] += dp[i][o][j][k]
#                             dp[i + 1][o][l][l] %= m

#     # for line in dp:
#     #     print(line)

#     cur = 0
#     for o in range(c):
#         for j in range(c):
#             for k in range(c):
#                 if j != o and k != o:
#                     cur += dp[n][o][j][k]
#                     cur %= m
            
#     print(cur)

#     ans += cur
#     ans %= m

# print(ans)



# BONUS
# encrypted = """
# Nwv whk, n ethical wn 'vy snwj'w pn-ratohrh. Rnwn'o ln-awzho lh 'dh!
# Dfa standard uhllhw vymyrht ht suv hg dkh ehrydyma ywdasatr l nwv m yr n
# uhllhw vymyrht hg l nwv m dfnd yr standat dfnw nwo hdfat uhllhw vymyrht hg l
# nwv m. Eht azalech:
# • dfa suv hg 8577 nwv 8577 yr 8577;
# • dfa suv hg 155 nwv 1071 yr 75;
# • dfa suv hg 7171 nwv 71500 yr 5;
# • dfa suv hg 928986 nwv 892396 yr 8;
# • dfa suv hg 76 nwv 58 yr 76.
# Wand 'wh? Wnslnond!
# Gjw gnud: Yw Znenwara yd yr unccav “rnyvny phjonpjrjj”; rn Phtanw wnln'o
# “ufhavnashwsonprj”. Rn pnrnlnnws encnv, entnws kncn r'onws Dnsnchs DhD.
# 'Ens dywnwhws lh wnlnw ry Shhsca, “eywnpnlncnpyws pntnwyknws vymyrht”
# 'ojws rnrniyfyw w'on. Entnws eycyd cnws 'vy in? RDAL ucnrrar yw EF dawv
# dh ia dnjsfd yw AWScyrf, ht nd iard DNScyrf (ht 'ojws tasyhwnc cnwsjnsa) kydf
# daufwyunc khtvr jwdtnwrcndav. Yd tancco lnpar ohj gaac cypa n lncnwrnws gyrf!
# Nwokno, tysfd, inup dh ethical. Whk, ka rno dfnd n dtyecad hg ehrydyma ywdasatr
# (n; o; i) yr pndnpndnpn yg yd rndyrgyar ncc hg dfa ghcchkyws:
# • dfa suv hg n nwv o yr i;
# • dfa vauylnc taetarawdndyhw hg n hwco jrar dfa vysydr 8, 1 nwv 6, nwv anuf
# hg dfhra neeantr nd canrd hwua;
# • dfa vauylnc taetarawdndyhw hg o hwco jrar dfa vysydr 3, 5 nwv 7, nwv anuf
# hg dfhra neeantr nd canrd hwua;
# • dfa vauylnc taetarawdndyhw hg i hwco jrar dfa vysydr 4, 9 nwv 2, nwv anuf
# hg dfhra neeantr nd canrd hwua.
# Ght hjt ejtehrar, dfa vauylnc taetarawdndyhw hg n ehrydyma ywdasat yr jwyqja
# nwv vharw'd fnma n canvyws bath.
# Nlhws ncc dtyecar (n; o; i) dfnd nta pndnpndnpn, kfnd yr dfa lywyljl ehrryica
# mncja hg noi?
# Idk ihwjr cnws 'dhws ethical wn 'dh! Zjrd ght gjw :E Dfyr ethical yr hwco khtdf
# 25 ehywdr. Ijd rdycc, pjws ln-rhcma lh r'on, ether dh ohj. Sjvcnp! Nwv yg ohj'ta
# nica dh tanv dfyr, ecanra rno yw dfa WHY ratmat dfnd dfyr ethical yr etaddo
# rdnwvntv (nwv adfyunc tyw r'oaleta)!
# """
