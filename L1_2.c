#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

int InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)
        exit(1);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return 0;
}

void CreateList(SqList *L, int n)
{
    int i;
    printf("输入%d个元素：\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &L->elem[i]);
    }
    L->length = n;
}

void DispList(SqList *L)
{
    int i;
    for (i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

int ListInsert_Sq(SqList *L, int i, ElemType e)
{
    ElemType *newbase, *q, *p;
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length >= L->listsize)
    {
        newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(1);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    q = &(L->elem[i - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++L->length;
    return 0;
}

void DeleteList(SqList *L, int i)
{
    int j;
    if (i < 1 || i > L->length)
    {
        printf("删除位置非法\n");
        exit(0);
    }
    printf("删除元素：%d\n", L->elem[i - 1]);
    for (j = i; j < L->length; j++)
    {
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;
}

int main()
{
    SqList L;
    int i, n, e;
    InitList_Sq(&L);
    printf("输入顺序表的长度：");
    scanf("%d", &n);
    CreateList(&L, n);
    printf("顺序表为：");
    DispList(&L);
    printf("输入插入的位置和元素：");
    scanf("%d%d", &i, &e);
    ListInsert_Sq(&L, i, e);
    printf("插入后的顺序表为：");
    DispList(&L);
    printf("输入删除的位置：");
    scanf("%d", &i);
    DeleteList(&L, i);
    printf("删除后的顺序表为：");
    DispList(&L);
    system("pause");
    return 0;
}