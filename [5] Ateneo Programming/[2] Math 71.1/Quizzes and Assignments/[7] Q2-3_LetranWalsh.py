def solve():
    x1, y1, r1 = [int(x) for x in input().split()]
    x2, y2, r2 = [int(x) for x in input().split()]

    if abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1) > (r1 + r2) * (r1 + r2):
        print(0)
        return

    x_min, y_min = min(x1, x2) - max(r1, r2), min(y1, y2) - max(r1, r2)
    x_max, y_max = max(x1, x2) + max(r1, r2), max(y1, y2) + max(r1, r2) 

    # print(x_min, y_min)
    # print(x_max, y_max)

    ans = 0
    for x in range(x_min, x_max + 1):
        for y in range(y_min, y_max + 1):
            d1 = abs(x1 - x) * abs(x1 - x) + abs(y1 - y) * abs(y1 - y)
            d2 = abs(x2 - x) * abs(x2 - x) + abs(y2 - y) * abs(y2 - y)
            
            ans += d1 <= r1 * r1 and d2 <= r2 * r2

    print(ans)
    
    return

solve()