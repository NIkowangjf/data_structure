#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// 定义栈结构
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

// 初始化栈
void initCharStack(CharStack *stack) {
    stack->top = -1;
}

// 判断栈是否为空
bool isEmpty(CharStack *stack) {
    return stack->top == -1;
}

// 入栈
void push(CharStack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("栈已满，无法入栈\n");
    }
}

// 出栈
char pop(CharStack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("栈为空，无法出栈\n");
        return '\0'; // 返回空字符，表示栈为空
    }
}

// 匹配括号
bool matchBrackets(char expr[]) {
    CharStack stack;
    initCharStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        char currentChar = expr[i];
        if (currentChar == '(' || currentChar == '[') {
            push(&stack, currentChar);
        } else if (currentChar == ')' || currentChar == ']') {
            if (isEmpty(&stack)) {
                return false; // 没有左括号匹配
            }

            char topChar = pop(&stack);
            if ((currentChar == ')' && topChar != '(') || (currentChar == ']' && topChar != '[')) {
                return false; // 括号不匹配
            }
        }
    }

    // 检查是否所有括号都匹配
    return isEmpty(&stack);
}

int main() {
    char expr[100];
    printf("请输入表达式: ");
    scanf("%s", expr);
    if (matchBrackets(expr)) {
        printf("括号匹配\n");
    } else {
        printf("括号不匹配\n");
    }
    system("pause");
    return 0;
}
