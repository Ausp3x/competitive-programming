Interpolation(f, *argv):
#     t_0 = argv[0]
#     τ = mpf("0.001")

#     fs = [None for _ in range(6)]
#     for i in range(-2, 4):
#         fs[i] = f(t_0 + i * τ, *argv[1:])

#     Δ_2 =             fs[2] -      fs[1] -      fs[0] +     fs[-1]
#     Δ_3 =             fs[2] -  3 * fs[1] +  3 * fs[0] -     fs[-1]
#     Δ_4 = fs[3] - 3 * fs[2] +  2 * fs[1] +  2 * fs[0] - 3 * fs[-1] + fs[-2]
#     Δ_5 = fs[3] - 5 * fs[2] + 10 * fs[1] - 10 * fs[0] + 5 * fs[-1] - fs[-2]

#     p = [0, 0]
#     cnt = 0
#     for _ in range(1000):
#         B_2 = p[cnt] * (p[cnt] - 1) / 4
#         B_3 = p[cnt] * (p[cnt] - mpf('0.5')) * (p[cnt] - 1) / 6
#         B_4 = (p[cnt] + 1) * p[cnt] * (p[cnt] - 1) * (p[cnt] - 2) / 48
#         B_5 = (p[cnt] + 1) * p[cnt] * (p[cnt] - mpf('0.5')) * (p[cnt] - 1) * (p[cnt] - 2) / 120

#         p[cnt ^ 1] = (fs[0] + B_2 * Δ_2 + B_3 * Δ_3 + B_4 * Δ_4 + B_5 * Δ_5) / (fs[0] - fs[1]) 
#         cnt ^= 1
    
#         if p[cnt].imag == 0 and p[cnt ^ 1].imag == 0:
#             if abs(p[cnt].real - p[cnt ^ 1].real) < mpf('0.000001'):
#                 return t_0 + p[cnt] * τ
    
#     return None
