#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

// ����˳��ջ�ṹ
typedef struct {
    int data[MAX_SIZE];
    int top; // ջ��ָ��
} Stack;

// ��ʼ��˳��ջ
void initStack(Stack *stack) {
    stack->top = -1;
}

// ����˳��ջ����ѡ������ͨ��initStack���г�ʼ����
Stack createStack() {
    Stack stack;
    initStack(&stack);
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// ���˳��ջ
void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
    } else {
        printf("ջ��Ԫ��Ϊ: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

// ȡջ��Ԫ��
int top(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    } else {
        printf("ջΪ�գ��޷�ȡջ��Ԫ��\n");
        return -1; // ����һ��Ĭ��ֵ����ʾջΪ��
    }
}

// ��ջ
void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("ջ�������޷���ջ\n");
    }
}

// ��ջ
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("ջΪ�գ��޷���ջ\n");
        return -1; // ����һ��Ĭ��ֵ����ʾջΪ��
    }
}

int main() {
    Stack stack = createStack();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    displayStack(&stack);

    int topElement = top(&stack);
    printf("ջ��Ԫ��: %d\n", topElement);

    int poppedValue = pop(&stack);
    printf("��ջ��Ԫ��: %d\n", poppedValue);

    displayStack(&stack);
    system("pause");
    return 0;
}
