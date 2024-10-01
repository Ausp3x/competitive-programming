n = int(input())
p = [int(x) for x in input().split()]
q = [int(x) for x in input().split()]

ans = [0 for _ in range(n + len(q))]
for i in range(len(q)):
    for j in range(n + 1):
        ans[i + j] += q[i] * p[j]
        
print(*ans)