#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义顺序栈结构
typedef struct {
    int data[MAX_SIZE];
    int top; // 栈顶指针
} Stack;

// 初始化顺序栈
void initStack(Stack *stack) {
    stack->top = -1;
}

// 创建顺序栈（可选，可以通过initStack进行初始化）
Stack createStack() {
    Stack stack;
    initStack(&stack);
    return stack;
}

// 判断栈是否为空
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 输出顺序栈
void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
    } else {
        printf("栈中元素为: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

// 取栈顶元素
int top(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    } else {
        printf("栈为空，无法取栈顶元素\n");
        return -1; // 返回一个默认值，表示栈为空
    }
}

// 入栈
void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("栈已满，无法入栈\n");
    }
}

// 出栈
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("栈为空，无法出栈\n");
        return -1; // 返回一个默认值，表示栈为空
    }
}

int main() {
    Stack stack = createStack();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    displayStack(&stack);

    int topElement = top(&stack);
    printf("栈顶元素: %d\n", topElement);

    int poppedValue = pop(&stack);
    printf("出栈的元素: %d\n", poppedValue);

    displayStack(&stack);
    system("pause");
    return 0;
}
