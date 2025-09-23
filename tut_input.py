n = int(input('nhap mot so ngau nhien:')) #ep kieu sau khi input
print(f'ban vua nhap so: {n}, kieu du lieu cua n: {type(n)}')

s = input('tin hieu duyet binh:')
_str = s.split() #tach string thanh list
a, b = _str #unpack list
print(f'anh em len phim: {a}, duyet binh tai: {b} ang lieng', end = '\n')

#tinh tong 4 so
x, y, z, t = map(float, input().split())
print(x + y + z + t)