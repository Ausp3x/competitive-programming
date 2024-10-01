exercise = input('Exercise: ')
match exercise:
    case '1.1.1':
        print('Exponentiation syntax is ** not ^.')
    case '1.1.2':
        print('Parentheses required around 2 + 1.')
    case '1.1.5':
        print('Parentheses required around 6 + 6.')
    case '1.1.6a':
        print('false', (11 - 1) * (1 + 1 + 1) - (11 - 1) // (1 + 1))
    case '1.1.6d':
        print('true', 4 + (4 - 4 // 4) ** (4 + (4 + 4) // 4))
    case '1.1.7':
        print('a. 0')
        print('b. 1')
        print('c. 0, 2')
        print('d. 1, 3')
        print('e. no')