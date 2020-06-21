def printPattern(l, c):
    for i in range(l):
        if i == 0 or i == l-1:
            line = "".join(["*"] * c)
        else:
            line = []
            for j in range(c):
                if j == 0 or j == c-1:
                    line.append("*")
                else:
                    line.append(".")
            line = "".join(line)
        print(line)


t = int(input())
for i in range(t):
    l, c = map(int, input().split())
    printPattern(l, c)
    if i != t-1:
        print()
