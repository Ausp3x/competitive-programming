cnt = 0
for i in range(5):
    for j in range(0, 101):
        print(1, i, j)
        cnt += 1
for i in range(5):
    for j in range(0, 101):
        print(2, i, j)
        cnt += 1
for i in range(5):
    for j in range(999999900, 1000000001):
        print(1, i, j)
        cnt += 1
for i in range(5):
    for j in range(999999900, 1000000001):
        print(2, i, j)
        cnt += 1
print(cnt)