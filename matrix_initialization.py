n, m = 2, 3
a = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    a[i] = list(map(int, input().split()))

for i in range(n):
    for j in range(m):
        print(a[i][j], end = " ")
    print() # = print("\n")
