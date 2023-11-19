def is_matching(expression):
    stack = []  # 用于存储左括号的栈

    # 定义左右括号的映射关系
    brackets_map = {')': '(', ']': '[', '}': '{'}

    for char in expression:
        if char in '({[':
            # 如果是左括号，入栈
            stack.append(char)
        elif char in ')}]':
            # 如果是右括号
            if not stack or stack[-1] != brackets_map[char]:
                # 如果栈为空或者栈顶的左括号与当前右括号不匹配，返回0
                return 0
            stack.pop()  # 匹配成功，弹出左括号

    # 如果栈为空，说明括号全部匹配
    return int(not stack)

# 输入算术表达式
expression = input("请输入算术表达式: ")

# 输出结果
result = is_matching(expression)
print(result)
