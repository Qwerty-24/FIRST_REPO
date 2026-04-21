a = 3e6 #can save big number
# a = 3e6 + 0,36 -> tuple
print (a, 'kieu du lieu cua a:', type(a), end = '\n')

b = 5+5j
print ('kieu du lieu cua b:', type(b), end = '\n')
print ('phan thuc:', b.real)
print ('phan ao:', b.imag)

c = 0b1011 #binary 
# 0o - octal
# 0x - hexcadecimal 
print ('kieu du lieu cua c:', type(c), end = '\n\n')

d = 120.3636
print ('%.2f' % d) #format number
print ('{:.2f}'.format(d)) #format number
print (f'{d:.2f}') #format number
print (round(d, 2), end = '\n\n') #lam tron (tai sao can 2 cai \n moi xuong dong?)

bool1 = True
print (type(bool1))

bool2 = ''
print (bool(bool2), end = '\n\n')

s = 'i cant fix her'    
print (type(s))