slash = ["/", "\\"]

t = int(input())
for i in range(t):
    rows, columns, s = list(map(int, input().split()))
    chrInLine = s * columns + columns + 1
    dots = ["."] * s
    line = (["*"] + dots) * columns + ["*"]
    
    for noRow in range(rows):
        print("".join(["*"] * chrInLine))
        for noLine in range(s):
            thisLine = line.copy()
            if noRow%2 == 0:
                for elem in range(1, chrInLine, 2*(s+1)):
                    thisLine[noLine+elem] = "\\"
                for elem in range(2*s+2, chrInLine, 2*(s+1)):
                    thisLine[elem-noLine-1] = "/"
            else:
                for elem in range(s+2, chrInLine, 2*(s+1)):
                    thisLine[noLine+elem] = "\\"
                for elem in range(s, chrInLine, 2*(s+1)):
                    thisLine[elem-noLine] = "/"
            print("".join(thisLine))
    print("*" * chrInLine)
    print()