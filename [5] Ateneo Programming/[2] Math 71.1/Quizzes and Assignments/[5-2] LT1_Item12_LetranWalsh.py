import math

def getLen(p1, p2):
    return math.sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]))
    
points = [list(map(int, input().split())) for _ in range(3)]

sides = []
for [i, j] in [[0, 1], [0, 2], [1, 2]]:
    sides.append(getLen(points[i], points[j]))

chk = False
err = 1e-9
for [i, j] in [[0, 1], [0, 2], [1, 2]]:
    if abs(sides[i] - sides[j]) < err:
        chk = True
        print('ISOSCELES')
        print(f'{sides[i]:.8f}')
        
if not chk:
    print('SCALENE')