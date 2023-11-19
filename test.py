def infix_to_postfix(infix_expression):
    # 定义运算符的优先级
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '(': 0, '#': -1}

    # 初始化一个空栈用于运算符处理
    operators = []

    # 用于存储后缀表达式的列表
    postfix_expression = []

    for symbol in infix_expression:
        if symbol.isalpha():
            # 如果是字母，直接加入后缀表达式
            postfix_expression.append(symbol)
        elif symbol == '(':
            # 如果是左括号，入栈
            operators.append(symbol)
        elif symbol == ')':
            # 如果是右括号，将栈顶的运算符弹出并加入后缀表达式，直到遇到左括号
            while operators and operators[-1] != '(':
                postfix_expression.append(operators.pop())
            operators.pop()  # 弹出左括号
        else:
            # 如果是运算符
            while operators and precedence[symbol] <= precedence[operators[-1]]:
                # 当栈不为空且栈顶运算符优先级大于等于当前运算符时，将栈顶运算符弹出
                postfix_expression.append(operators.pop())
            # 将当前运算符入栈
            operators.append(symbol)

    # 将栈中剩余的运算符全部弹出
    while operators:
        postfix_expression.append(operators.pop())

    # 将列表转为字符串
    return ''.join(postfix_expression)

# 输入中缀表达式
infix_expression = input("请输入中缀表达式，以#结束: ")

# 输出后缀表达式
postfix_expression = infix_to_postfix(infix_expression + '#')
print("后缀表达式:", postfix_expression)
