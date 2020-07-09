t = int(input())
for i in range(t):
    rows, columns, h, w = list(map(int, input().split()))
    chrInLine = w * columns + columns + 1
    dots = "." * w
    line = ("*" + dots) * columns + "*"
    for j in range(rows):
        print("*" * chrInLine)
        for a in range(h):
            print(line)
    print("*" * chrInLine)
    print()