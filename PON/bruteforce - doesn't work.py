n = int(input())
for i in range(0, n):
    x = int(input())
    prime = "YES"
    if x % 2 == 0:
        prime = "NO"
    else:
        for j in range(3, int(x**(1/2)), 2):
            if x % j == 0:
                prime = "NO"
                break
    print(prime)