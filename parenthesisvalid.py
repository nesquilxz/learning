def isValid(s):
    pilha = []

    for c in s:
        # se for abertura, guarda
        if c == '(' or c == '[' or c == '{':
            pilha.append(c)

        # se for fechamento, tem que ver se a última abertura é do mesmo tipo que fechou
        elif c == ')':
            if not pilha or pilha[-1] != '(':
                return False
            pilha.pop()

        elif c == ']':
            if not pilha or pilha[-1] != '[':
                return False
            pilha.pop()

        elif c == '}':
            if not pilha or pilha[-1] != '{':
                return False
            pilha.pop()

    return len(pilha) == 0
