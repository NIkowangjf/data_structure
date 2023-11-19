#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 逆置链表
void ReverseLinkedList(LinkList L) {
    if (L == NULL || L->next == NULL) {
        return; // 空链表或只有一个结点无需逆置
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
    LinkList L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    L->next = NULL;

    // 创建一个示例链表
    for (int i = 1; i <= 5; i++) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = i;
        node->next = L->next;
        L->next = node;
    }

    printf("原链表：");
    LinkList cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    ReverseLinkedList(L);

    printf("\n逆置后：");
    cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    system("pause");
    return 0;
}