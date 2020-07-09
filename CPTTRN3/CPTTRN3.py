t = int(input())
for i in range(t):
    rows, columns = list(map(int, input().split()))
    chrInLine = 3*columns + 1
    line = "*.." * columns + "*"
    for j in range(rows):
        print("*" * chrInLine)
        print(line)
        print(line)
    print("*" * chrInLine)
    print()