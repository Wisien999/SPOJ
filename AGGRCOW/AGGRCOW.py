def distPoss(dist, cows, numbers):
    cows -= 1
    last = 0
    for i in range(1, len(numbers)):
        if numbers[i] - numbers[last] >= dist:
            cows -= 1
            last = i
        if cows == 0:
            return True
    return False


def binarySearch(c, num):
    p, q = 1, 2000000000
    dist = 0
    while p < q:
        # print("p:", p, "q:", q)
        s = (p+q)//2
        # print("distance", s, "returned", distPoss(s, c, num))
        if distPoss(s, c, num):
            p = s + 1
            dist = s
        else:
            q = s
    return dist
    

t = int(input())
for j in range(t):
    n, c = list(map(int, input().split()))
    numb = [int(input()) for i in range(n)]

    numb.sort()

    print(binarySearch(c, numb))
