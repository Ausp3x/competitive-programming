# exercise = input('Exercise: ')
exercise = '1.2.13'
match exercise:
    case '1.2.2':
        x = float(input())
        y = float(input())
        
        x = int(x * 100)
        y = int(y * 100)
        
        print(x != y)
    case '1.2.4':
        n = int(input())
        m = int(input())
        
        print(n % 2 == 0 and m % 2 == 0)
    case '1.2.7':
        h1 = float(input())
        h2 = float(input())
        
        print((h1 >= 150 and h2 >= 150) or (h1 > 180 and h2 < 140) or (h1 < 140 and h2 > 180))
    case '1.2.9':
        w = input()
        
        print(w[0] == 'a' or w[0] == 'e' or w[0] == 'i' or w[0] == 'o' or w[0] == 'u')
    case '1.2.13':
        w = input()
        u = input()
        
        print(u[0:3] == w or u[1:4] == w or u[2:5] == w)