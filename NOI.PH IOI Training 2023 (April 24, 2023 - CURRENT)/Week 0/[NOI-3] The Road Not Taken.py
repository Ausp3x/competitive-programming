t = int(input())

while t > 0:
    n, m = map(int, input().split())
    print("CONVERGE" if m == n - 1 else "DIVERGE", flush=True)
    t -= 1