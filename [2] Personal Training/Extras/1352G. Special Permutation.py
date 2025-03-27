def solve():
    n = int(input())
    
    if n <= 3:
        print(-1)
        return
    
    left = []
    right = []
    for i in range(5, n + 1):
        if i % 2 == 0:
            left.append(i)
        else:
            right.append(i)

    print(*(left[::-1] + [2, 4, 1, 3] + right))

    return

t = int(input())
while t > 0:
    solve()

    t -= 1