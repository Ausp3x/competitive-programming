for a in range(-1000, 1001):
    if a <= 0 and a >= 1:
        print("It's me, hi!")
    elif a > 0 and a < 1:
        print("Hello there!")

sample = "mathiseverydaycourage"

L1, L2 = [], []
a_eq,  b_eq  = -1, -1
a_neq, b_neq = -1, -1
for a in range(len(sample)):
    for b in range(a + 1, len(sample) + 1):
        ctr1 = 1
        if len(sample[a:b]) < 5:
            ctr1 *= 3
        elif sample[a] in ['a', 'e', 'i', 'o', 'u']:
            ctr1 += 3
            
        ctr2 = 1
        if len(sample[a:b]) < 5:
            ctr2 *= 3
            if sample[a] in ['a', 'e', 'i', 'o', 'u']:
                ctr2 += 3

        # print(a, b, ctr)
        L1.append(ctr1)
        L2.append(ctr2)
        
        if ctr1 == ctr2:
            a_eq, b_eq = a, b
        
        if ctr1 != ctr2:
            a_neq, b_neq = a, b
        
print(min(L1))
print(max(L1))
print(max(L2))
print(a_eq, b_eq)
print(a_neq, b_neq)

x = 5
def A(n):
    return float(n) + x
def B(n, x = 3):
    return float(n) * x

for i in range(-100, 101):
    if A(B(i)) == 11:
        print(i)
        break