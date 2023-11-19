#include <stdio.h>
#include <stdlib.h>
#define maxsize 50
typedef int ElemType;
typedef struct
{
    ElemType data[maxsize]; //���˳���Ԫ��
    int length; //���˳���ĳ���
} SqList;

//��ʼ��˳���
void InitList(SqList *L)
{
    L->length = 0;
}

//����n��Ԫ�ص�˳���
void CreateList(SqList *L, int n)
{
    int i;
    printf("����%d��Ԫ�أ�\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &L->data[i]);
    }
    L->length = n;
}

//�жϿձ�
int EmptyList(SqList *L)
{
    return (L->length == 0);
}

//��˳���ĳ���
int LengthList(SqList *L)
{
    return (L->length);
}

//���˳���
void DispList(SqList *L)
{
    int i;
    if (EmptyList(L))
    {
        printf("˳���Ϊ�ձ�\n");
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

//��˳�����ĳ��Ԫ��ֵ
int GetElem(SqList *L, int i)
{
    if (i < 1 || i > L->length)
    {
        printf("����λ�÷Ƿ�\n");
        exit(0);
    }
    else
    {
        return (L->data[i - 1]);
    }
}

//��Ԫ��ֵ����
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

//����Ԫ��
void InsertList(SqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
    {
        printf("����λ�÷Ƿ�\n");
        exit(0);
    }
    if (L->length >= maxsize)
    {
        printf("˳����������޷�����\n");
        exit(0);
    }
    for (j = L->length - 1; j >= i - 1; j--)
    {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = e;
    L->length++;
}

//ɾ��Ԫ��
void DeleteList(SqList *L, int i)
{
    int j;
    if (i < 1 || i > L->length)
    {
        printf("ɾ��λ�÷Ƿ�\n");
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
    printf("˳���ĳ���Ϊ��%d\n", LengthList(&L));
    printf("������Ҫ���ҵ�λ�ã�");
    scanf("%d", &a);
    dd = GetElem(&L, a);
    printf("��%d��Ԫ�ص�ֵΪ��%d\n", a, dd);
    printf("������Ҫ���ҵ�Ԫ��ֵ��");
    scanf("%d", &b);
    dd = LocateElem(&L, b);
    if (dd == 0)
    {
        printf("û���ҵ�\n");
    }
    else
    {
        printf("Ԫ��%d��λ��Ϊ��%d\n", b, dd);
    }
    printf("������Ҫ�����λ�ú�Ԫ��ֵ��");
    scanf("%d%d", &a, &b);
    InsertList(&L, a, b);
    DispList(&L);
    printf("������Ҫɾ����Ԫ��λ�ã�");
    scanf("%d", &a);
    DeleteList(&L, a);
    DispList(&L);
    system("pause");
    return 0;
}