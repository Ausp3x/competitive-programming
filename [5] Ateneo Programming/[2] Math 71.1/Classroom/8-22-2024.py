# exercise = input('Exercise: ')
exercise = '1.2.42'
match exercise:
    case '1.2.29':
        gender = input()
        tense = input()
        
        output = ''
        if gender == 'male':
            output += 'He '
        elif gender == 'female':
            output += 'She '
        elif gender == 'other':
            output += 'They '
            
        if gender == 'male' or gender == 'female':
            if tense == 'past':
                output += 'was '
            elif tense == 'present':
                output += 'is '
            elif tense == 'future':
                output += 'will be '
        elif gender == 'other':
            if tense == 'past':
                output += 'were '
            elif tense == 'present':
                output += 'are '
            elif tense == 'future':
                output += 'will be '
        
        output += 'happy.'
        
        print(output)
    case '1.2.34':
        s1 = input()
        p1 = int(input())
        s2 = input()
        p2 = int(input())
        s3 = input()
        p3 = int(input())
        
        if p1 > p2 + p3 or p2 > p1 + p3 or p3 > p1 + p2:
            print('Yes')
            if p1 > p2 + p3:
                print(s1)
            elif p2 > p1 + p3:
                print(s2)
            elif p3 > p1 + p2:
                print(s3)
        else:
            print('No')
    case '1.2.40':
        name = input()
        fav_color = input()
        age = int(input())
        height = int(input())
        
        print((len(name) <= 5) + (fav_color[0] == 'B' or fav_color[0] == 'b') + (20 <= age <= 25) + (height >= 150))
    case '1.2.42':
        s1 = input()
        s2 = input()
        rot = input()
        
        s1_new = ''
        s2_new = ''
        if rot == 'cw':
            s1_new = s2[0] + s1[0]
            s2_new = s2[1] + s1[1]
        elif rot == 'ccw':
            s1_new = s1[1] + s2[1]
            s2_new = s1[0] + s2[0]
            
        print(f'{s1_new}\n{s2_new}')
    