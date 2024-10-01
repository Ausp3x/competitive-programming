n = int(input())
A = list(map(int, input().split()))

A.sort()

print(f'mean: {(sum(A) / n):.2f}')
print(f'median: {((A[n // 2 - 1] + A[n // 2]) / 2 if n % 2 == 0 else A[n // 2]):.2f}')