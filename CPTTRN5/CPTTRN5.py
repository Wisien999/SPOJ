# get number of tests
t = int(input())

for i in range(t):
    # get input
    rows, columns, s = list(map(int, input().split()))
    # prepare empty grid
    chrInLine = s * columns + columns + 1
    dots = ["."] * s
    line = (["*"] + dots) * columns + ["*"]
    
    for noRow in range(rows):
        # print ****** line
        print("".join(["*"] * chrInLine))
        # calculate every non-****** line
        for noLine in range(s):
            thisLine = line.copy()
            # if line odd start with \
            if noRow%2 == 0:
                for elem in range(1, chrInLine, 2*(s+1)):
                    thisLine[noLine+elem] = "\\"
                for elem in range(2*s+2, chrInLine, 2*(s+1)):
                    thisLine[elem-noLine-1] = "/"
            # otherwise start with /
            else:
                for elem in range(s+2, chrInLine, 2*(s+1)):
                    thisLine[noLine+elem] = "\\"
                for elem in range(s, chrInLine, 2*(s+1)):
                    thisLine[elem-noLine] = "/"
            # print this line
            print("".join(thisLine))
    # print ******* line to complete the grid
    print("*" * chrInLine)
    print()