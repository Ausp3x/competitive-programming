N = 30
facs = [1 for _ in range(N + 1)]
for i in range(2, N + 1):
    facs[i] = facs[i - 1] * i

def choose(n, k):
    return facs[n] // facs[n - k] // facs[k]

def solve():
    R, S, X, Y, W = map(int, input().split())

    numer = 0
    for i in range(X, Y + 1):
        # print(choose(Y, i) * ((S - R + 1) ** i) * ((R - 1) ** (Y - i)))
        numer += choose(Y, i) * ((S - R + 1) ** i) * ((R - 1) ** (Y - i))
    numer *= W
    
    denom = S ** Y
    # print(numer, denom)
    
    print('yneos'[(numer <= denom)::2])

    return

t = int(input())
while t > 0:
    solve()
    
    t -= 1