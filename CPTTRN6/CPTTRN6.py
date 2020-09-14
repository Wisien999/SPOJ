t = int(input())

for _ in range(t):
    l, c, h, w = map(int, input().split())
    horEl = ["-"] * (w*(c+1)+c)
    dots = "." * w

    for verticalRectangles in range(l):
        for hight in range(h):
            for horizontalRectangles in range(c):
                print(dots, "|", sep="", end="")
            print(dots)
        for i in range(w, len(horEl), w+1):
            horEl[i] = "+"
        print("".join(horEl))
    
    for hight in range(h):
        for horizontalRectangles in range(c):
            print(dots, "|", sep="", end="")
        print(dots)
        for i in range(w, len(horEl), w+1):
            horEl[i] = "+"