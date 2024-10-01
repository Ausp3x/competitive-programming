exercise = input('Exercise: ')
match exercise:
    case '1.1.10':
        x = float(input())
        n = int(input())

        res = x ** (1 / n)
        print(f'{res:.5f}')
    case '1.1.13':
        a = int(input())
        b = int(input())
        c = int(input())
        
        res = 1000 - (a + b + c) * 1.05
        print(f'{res:.2f}')
    case '1.1.16':
        name = input()
        position = input()
        
        print(f'{position}: {name}')
    case '1.1.18':
        x = int(input())
        
        print(f'boxes: {x // 12}')
        print(f'individual donuts: {x % 12}')
        print(f'total cost: ${8 * (x // 12) + x % 12}')
    case '1.1.23':
        s = input()
        x = int(s[:len(s) - 2])
        
        print(f'{2 * x}MB')
    case '1.1.28a':
        s = input()
        
        res = 0
        for c in s:
            res += int(c)
            
        print(res)
    case '1.1.28b':
        s = int(input())
        
        res = 0
        while s > 0:
            res += s % 10
            s //= 10
            
        print(res)