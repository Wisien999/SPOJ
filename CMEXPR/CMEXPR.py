def findBrackets(text, start):
    opBrIndex = text[start:].find("(")
    balance = 1
    for i in range(start+1, len(text)):
        if text[i] == "(":
            balance += 1
        elif text[i] == ")":
            balance -= 1
        if balance == 0:
            return opBrIndex, i


def simplify(text):
    openingBracketIndex, closingBracketIndex = 0, 0
    while openingBracketIndex >= 0:
        openingBracketIndex, closingBracketIndex = findBrackets(text, closingBracketIndex)
    	part = simplify(text[openingBracketIndex+1:closingBracketIndex])

    # in case text='x' brackets can be removed
    if len(text) == 1:
        return text, True

    
