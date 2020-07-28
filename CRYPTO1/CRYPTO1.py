import datetime
p = 4000000007
k = 1000000001
a = int(input())


time = pow(a, k+1, p)

if time > p / 2:
    noOfSec = p - time
else:
    noOfSec = time

myDate = datetime.datetime(1970, 1, 1, 00, 00)
attackDate=myDate+datetime.timedelta(seconds=noOfSec)

print(attackDate.ctime())