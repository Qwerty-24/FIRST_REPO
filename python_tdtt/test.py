def square_matrix_of_n(n):
    s = ""
    for i in range (1, n+1):
        s += f"{n} " * n
        # s.strip()
        s += "\n"

    s.rstrip()
    return s

print (square_matrix_of_n(1))