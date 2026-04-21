#19.3
import sys #system
# tokens = sys.stdin.read().split() -> doc het 1 lan -> don gian nhung ton bo nho neu input lon

for line in sys.stdin: #streaming -> khong doc het bo nho
    line = line.strip() #loai bo khoang trang (space, tab, \n, ...) o dau va cuoi str
    if not line: continue #neu sau strip() str rong -> bo qua lan lap nay
    if int(line) == 19: print(19); break
else: #else chay khi for ket thuc normal (khong bi break)
    print ("impossible")