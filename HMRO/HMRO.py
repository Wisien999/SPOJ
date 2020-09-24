def getMRO(assigments, key):
    if assigments[key] == key:
        return key
    else:
        return getMRO(assigments, assigments[key])


t = int(input())
for _ in range(t):
    p = int(input())
    assigment = {}
    for __ in range(p):
        pesel, mro = input().split(" ")
        assigment[pesel] = mro
        assigment[mro] = mro

    z = int(input())
    # redirection = {}
    for __ in range(z):
        old_mro, new_mro = input().split(" ")
        assigment[old_mro] = new_mro
    
    # print(assigment)
    # print(redirection)

    p = int(input())
    for __ in range(p):
        pesel = input()
        print(pesel, getMRO(assigment, pesel))

    print()