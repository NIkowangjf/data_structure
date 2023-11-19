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

void MergeList_Sq(SqList La,SqList Lb,SqList *Lc)
{
    ElemType *pa,*pb,*pc,*pa_last,*pb_last;
    pa=La.elem;
    pb=Lb.elem;
    Lc->listsize=Lc->length=La.length+Lb.length;
    pc=Lc->elem=(ElemType *)malloc(Lc->listsize*sizeof(ElemType));
    if(!Lc->elem)
        exit(1);
    pa_last=La.elem+La.length-1;
    pb_last=Lb.elem+Lb.length-1;
    while(pa<=pa_last&&pb<=pb_last)
    {
        if(*pa<=*pb)
            *pc++=*pa++;
        else
            *pc++=*pb++;
    }
    while(pa<=pa_last)
        *pc++=*pa++;
    while(pb<=pb_last)
        *pc++=*pb++;
}

int main()
{
    SqList La, Lb, Lc;
    int n, m;
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    printf("输入La的元素个数：");
    scanf("%d", &n);
    CreateList(&La, n);
    printf("输入Lb的元素个数：");
    scanf("%d", &m);
    CreateList(&Lb, m);
    MergeList_Sq(La, Lb, &Lc);
    printf("La和Lb合并后的结果：");
    DispList(&Lc);
    system("pause");
    return 0;
}