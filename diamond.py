
k, border, inner, stitch = map(str, input().split())
k = int(k)

a = []
b = []

for i in range (0, k):
    # hang lon nhat co 2k - 1 ki tu
    #tong phan tu tren moi hang: 2k + 1
    res = ""
    if (i != k-1):
        res += " "*(k-i-1) + border
        if (i != 0):
            res += inner * (2*i-1) + border
        # res += " "*(k-i-1)
        # res += "\n"
    else:
        res += " "*(k-i-1) + stitch
        if (i != 0):
            res += inner * (2*i-1) + stitch
        # res += " "*(k-i-1)
    a.append(res)

for i in range (0, k):
    res = ""
    if (i != k-1):
        res += " "*(k-i-1) + border
        if (i != 0):
            res += inner * (2*i-1) + border
        # res += " "*(k-i-1)
        # res += "\n"
    b.append(res)

b.reverse()


for j in range(0, len(a)):
    if (j != len(a)-1):
        print(a[j], sep = "", end = "\n")
    else:
        print(a[j], sep = "", end = "")
for j in range(0, len(b)):
    print(b[j], sep = "", end = "\n")


