n = int(input())
doors = list(map(str, input().split()))
inp1 = list(map(str, input().split()))
inp2 = list(map(str, input().split()))

assert(len(inp1) == 4 and len(inp2) == 4)

start = int(inp1[3][:-1]) - 1
move = int(inp2[1])
direc = inp2[3][:-1]

# print(start, move, direc)

if direc == 'clockwise':
    print(doors[(start + move) % n])
elif direc == 'counterclockwise':
    print(doors[(start - move) % n])