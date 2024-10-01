a, b, c, d = float(input()), float(input()), float(input()), float(input())

l, r = max(a, c), min(b, d)
eps = 0.000001
if l - r > eps:
    print('null set')
elif -eps <= l - r <= eps:
    print(f'{l:.2f}')
else:
    print(f'[{l:.2f},{r:.2f}]')