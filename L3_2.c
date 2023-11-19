#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// ��������
void ReverseLinkedList(LinkList L) {
    if (L == NULL || L->next == NULL) {
        return; // �������ֻ��һ�������������
    }

    LNode *prev = NULL;
    LNode *cur = L->next;
    LNode *next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    L->next = prev;
}

int main() {
    LinkList L = (LinkList)malloc(sizeof(LNode)); // ����ͷ���
    L->next = NULL;

    // ����һ��ʾ������
    for (int i = 1; i <= 5; i++) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = i;
        node->next = L->next;
        L->next = node;
    }

    printf("ԭ����");
    LinkList cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    ReverseLinkedList(L);

    printf("\n���ú�");
    cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    system("pause");
    return 0;
}