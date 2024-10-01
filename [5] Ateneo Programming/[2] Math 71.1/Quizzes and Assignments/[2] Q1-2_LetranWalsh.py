def solve():
    n = int(input())

    ends = ['th', 'st', 'nd', 'rd', 'th', 'th', 'th', 'th', 'th', 'th']
    if n in [11, 12, 13]:
        print(f'{n}th')
    else:
        print(f'{n}{ends[n % 10]}')

    return

t = 1
# t = int(input())
for i in range(t):
    solve()