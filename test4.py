def is_stack_sequence(input_length, input_sequence, output_sequence):
    stack = []
    output_index = 0
    pop_count = 0

    for num in input_sequence:
        stack.append(num)

        while stack and output_index < input_length and stack[-1] == output_sequence[output_index]:
            stack.pop()
            output_index += 1
            pop_count += 1

    return pop_count if output_index == input_length else 0

if __name__ == "__main__":
    # 输入序列的长度
    input_length = int(input())

    # 输入序列
    input_sequence = list(map(int, input().split()))

    # 输出序列
    output_sequence = list(map(int, input().split()))

    # 判断是否是出栈序列，并输出总的出栈次数
    result = is_stack_sequence(input_length, input_sequence, output_sequence)

    print(result)
