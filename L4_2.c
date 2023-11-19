#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// ����ջ�ṹ
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

// ��ʼ��ջ
void initCharStack(CharStack *stack) {
    stack->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(CharStack *stack) {
    return stack->top == -1;
}

// ��ջ
void push(CharStack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("ջ�������޷���ջ\n");
    }
}

// ��ջ
char pop(CharStack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("ջΪ�գ��޷���ջ\n");
        return '\0'; // ���ؿ��ַ�����ʾջΪ��
    }
}

// ƥ������
bool matchBrackets(char expr[]) {
    CharStack stack;
    initCharStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        char currentChar = expr[i];
        if (currentChar == '(' || currentChar == '[') {
            push(&stack, currentChar);
        } else if (currentChar == ')' || currentChar == ']') {
            if (isEmpty(&stack)) {
                return false; // û��������ƥ��
            }

            char topChar = pop(&stack);
            if ((currentChar == ')' && topChar != '(') || (currentChar == ']' && topChar != '[')) {
                return false; // ���Ų�ƥ��
            }
        }
    }

    // ����Ƿ��������Ŷ�ƥ��
    return isEmpty(&stack);
}

int main() {
    char expr[100];
    printf("��������ʽ: ");
    scanf("%s", expr);
    if (matchBrackets(expr)) {
        printf("����ƥ��\n");
    } else {
        printf("���Ų�ƥ��\n");
    }
    system("pause");
    return 0;
}
