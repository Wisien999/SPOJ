import math

t = int(input())
for _ in range(t):
    a,b,c,z,y,x = map(int, input().split())

    X = b**2 + c**2 - x**2
    Y = a**2 + c**2 - y**2
    Z = a**2 + b**2 - z**2

    V = math.sqrt(4*(a**2)*(b**2)*(c**2) - (a**2)*(X**2) - (b**2)*(Y**2) - (c**2)*(Z**2) + X*Y*Z)/12

    p1 = (a+b+x)/2
    p2 = (a+c+y)/2
    p3 = (x+z+y)/2
    p4 = (z+b+c)/2

    area1 = math.sqrt(p1*(p1-a)*(p1-b)*(p1-x))
    area2 = math.sqrt(p2*(p2-a)*(p2-c)*(p2-y))
    area3 = math.sqrt(p3*(p3-x)*(p3-z)*(p3-y))
    area4 = math.sqrt(p4*(p4-z)*(p4-b)*(p4-c))

    area = area1 + area2 + area3 + area4

    r = 3*V/area

    print("{:.4f}".format(round(r, 4)))