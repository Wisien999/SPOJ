import math


def minNoOfGames(avg):
    if float(avg) % 1 == 0:
        return 1
    dotPos = avg.find(".")
    aftercomm = avg[dotPos+1:]
    tenPow = 10**len(aftercomm)
    gcd = math.gcd(tenPow, int(aftercomm))
    return tenPow//gcd


t = int(input())
for i in range(t):
    print(minNoOfGames(input()))
