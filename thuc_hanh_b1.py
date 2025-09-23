# w2a1
print ("Hello world!")

# w2a2
name = input()
print(f"Hello {name}")

# w2a3
a, b = map (int, input().split())
# nhap ca dong bang input
# split -> tach so trong xau input
# map de ep kieu sang int
print(a + b)
print(a - b)
print(a * b)
print(a // b)
print(a % b)
print(f'{(a / b):.2f}')
# print('%.2f' % (a // b), end='\n')

# w2a4
a1, b1, c1, a2, b2, a3 = map (int, input().split('-'))
print (((a1+b1+c1)+(a2+b2)*2+a3*3)/10)

# w2a5
a, b = map (int, input().split())
print(a ** b)

# w2a6
s = input()
if (ord(s) >= 97 and ord(s) <= 122):
    print(chr(ord(s)-32))
# ord() -> tra ve ma ascii
# chr() -> tra ve ki tu tu ma ascii
else:
    print("invalid")


# w2a13
a, b = map(int, input().split())
print(a * b % 10)

# w2a14
a, b = map(int, input().split())
a, b = b, a
print(a, b)

# w2a21
for i in range(0, 9):
    print("hello world")
