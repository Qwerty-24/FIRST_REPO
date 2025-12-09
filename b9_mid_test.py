n = int(input())
a = []

for i in range(1, int(n**0.5) + 1):
    if n % i == 0:
        a.append(i)
        if i != n // i:
            a.append(n // i)

a.reverse()

for i in range(0, len(a)):
    check = True
    for j in range(2, int(a[i]**0.5) + 1):
        if a[i] % j == 0:
            check = False
            break

    if check and a[i] > 1:
        print(a[i])
        break
