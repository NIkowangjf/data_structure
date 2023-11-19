#include <stdio.h>
#include <stdlib.h>
#define maxsize 50
typedef int ElemType;
typedef struct
{
    ElemType data[maxsize]; //存放顺序表元素
    int length; //存放顺序表的长度
} SqList;

//初始化顺序表
void InitList(SqList *L)
{
    L->length = 0;
}

//创建n个元素的顺序表
void CreateList(SqList *L, int n)
{
    int i;
    printf("输入%d个元素：\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &L->data[i]);
    }
    L->length = n;
}

//判断空表
int EmptyList(SqList *L)
{
    return (L->length == 0);
}

//求顺序表的长度
int LengthList(SqList *L)
{
    return (L->length);
}

//输出顺序表
void DispList(SqList *L)
{
    int i;
    if (EmptyList(L))
    {
        printf("顺序表为空表\n");
        exit(0);
    }
    else
    {
        for (i = 0; i < L->length; i++)
        {
            printf("%d ", L->data[i]);
        }
        printf("\n");
    }
}

//求顺序表中某个元素值
int GetElem(SqList *L, int i)
{
    if (i < 1 || i > L->length)
    {
        printf("查找位置非法\n");
        exit(0);
    }
    else
    {
        return (L->data[i - 1]);
    }
}

//按元素值查找
int LocateElem(SqList *L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
    {
        i++;
    }
    if (i >= L->length)
    {
        return (0);
    }
    else
    {
        return (i + 1);
    }
}

//插入元素
void InsertList(SqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
    {
        printf("插入位置非法\n");
        exit(0);
    }
    if (L->length >= maxsize)
    {
        printf("顺序表已满，无法插入\n");
        exit(0);
    }
    for (j = L->length - 1; j >= i - 1; j--)
    {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = e;
    L->length++;
}

//删除元素
void DeleteList(SqList *L, int i)
{
    int j;
    if (i < 1 || i > L->length)
    {
        printf("删除位置非法\n");
        exit(0);
    }
    for (j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
}

int main()
{
    ElemType dd, a, b;
    SqList L;
    InitList(&L);
    CreateList(&L, 5);
    DispList(&L);
    printf("顺序表的长度为：%d\n", LengthList(&L));
    printf("请输入要查找的位置：");
    scanf("%d", &a);
    dd = GetElem(&L, a);
    printf("第%d个元素的值为：%d\n", a, dd);
    printf("请输入要查找的元素值：");
    scanf("%d", &b);
    dd = LocateElem(&L, b);
    if (dd == 0)
    {
        printf("没有找到\n");
    }
    else
    {
        printf("元素%d的位置为：%d\n", b, dd);
    }
    printf("请输入要插入的位置和元素值：");
    scanf("%d%d", &a, &b);
    InsertList(&L, a, b);
    DispList(&L);
    printf("请输入要删除的元素位置：");
    scanf("%d", &a);
    DeleteList(&L, a);
    DispList(&L);
    system("pause");
    return 0;
}