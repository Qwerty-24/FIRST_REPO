d, m, y = map(int, input().split())

def next_day(d, m, y):
    if(m in [1, 3, 5, 7, 8, 10, 12]):
        if (d > 31):
            return("Invalid Date")
        else:
            if (d == 31):
                if (m == 12):
                    y += 1
                    m = 1
                    d = 1
                else:
                    m += 1
                    d = 1
            else: 
                d += 1
    elif(m in [4, 6, 9, 11]):
        if (d > 30):
            return("Invalid Date")
        else:
            if (d == 30):
                m += 1
                d = 1
            else: d += 1
    else:
        if ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0):
            if (d > 29):
                return("Invalid Date")
            else:
                if (d == 29):
                    m += 1
                    d = 1
                else: d += 1
        else:
            if (d > 28):
                return("Invalid Date")
            else:
                if (d == 28):
                    m += 1
                    d = 1
                else: d += 1
    return(f"{d}/{m}/{y}")

print(next_day(d, m, y))
