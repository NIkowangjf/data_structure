def decimal_to_octal(decimal_num):
    # 判断输入是否为非负整数
    if not decimal_num.isdigit() or int(decimal_num) < 0:
        print("错误：请输入非负整数")
        return

    # 将十进制整数转换为八进制
    octal_num = oct(int(decimal_num))[2:]

    print(octal_num)

if __name__ == "__main__":
    # 用户输入十进制整数
    decimal_num = input()

    # 调用函数进行转换
    decimal_to_octal(decimal_num)
