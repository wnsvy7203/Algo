
for tc in range(1, 11):
    N = int(input())
    infix = list(input())
    infix_stack = []
    postfix = []

    for i in range(len(infix)):
        if infix[i].isdigit():
            postfix.append(infix[i])
        elif infix[i] == '+':
            if not infix_stack:
                infix_stack.append(infix[i])
            elif infix_stack[-1] == '+':
                postfix.append(infix_stack.pop())
                infix_stack.append(infix[i])
            elif infix_stack[-1] == '*':
                if len(infix_stack) == 1:
                    postfix.append(infix_stack.pop())
                    infix_stack.append(infix[i])
                else:
                    postfix.append(infix_stack.pop())
                    postfix.append(infix_stack.pop())
                    infix_stack.append(infix[i])
        elif infix[i] == '*':
            if (not infix_stack) or (infix_stack[-1] == '+'):
                infix_stack.append(infix[i])
            else:
                postfix.append(infix_stack.pop())
                infix_stack.append(infix[i])
    else:
        while infix_stack:
            postfix.append(infix_stack.pop())

    calculate = []
    for i in range(len(postfix)):
        if postfix[i].isdigit():
            calculate.append(postfix[i])
        elif postfix[i] == '+':
            a = calculate.pop()
            b = calculate.pop()
            calculate.append(int(a) + int(b))
        elif postfix[i] == '*':
            a = calculate.pop()
            b = calculate.pop()
            calculate.append(int(a)*int(b))
    print(f'#{tc}', *calculate)
