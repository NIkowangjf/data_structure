#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 按值非递减排列链表
void SortLinkedList(LinkList L) {
    if (L == NULL || L->next == NULL) {
        return; // 空链表或只有一个结点无需排序
    }
    LNode *cur = L->next;
    LNode *next = NULL;

    while (cur != NULL) {
        LNode *min = cur;
        next = cur->next;

        while (next != NULL) {
            if (next->data < min->data) {
                min = next;
            }
            next = next->next;
        }

        if (min != cur) {
            int temp = cur->data;
            cur->data = min->data;
            min->data = temp;
        }

        cur = cur->next;
    }
}

int main() {
    LinkList L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    L->next = NULL;

    // 创建一个示例链表
    LNode *node1 = (LNode *)malloc(sizeof(LNode));
    node1->data = 5;
    node1->next = L->next;
    L->next = node1;

    LNode *node2 = (LNode *)malloc(sizeof(LNode));
    node2->data = 2;
    node2->next = L->next;
    L->next = node2;

    LNode *node3 = (LNode *)malloc(sizeof(LNode));
    node3->data = 4;
    node3->next = L->next;
    L->next = node3;

    LNode *node4 = (LNode *)malloc(sizeof(LNode));
    node4->data = 1;
    node4->next = L->next;
    L->next = node4;

    LNode *node5 = (LNode *)malloc(sizeof(LNode));
    node5->data = 3;
    node5->next = L->next;
    L->next = node5;

    printf("原链表：");
    LinkList cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    SortLinkedList(L);

    printf("\n排序后：");
    cur = L->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    system("pause");
    return 0;
}
