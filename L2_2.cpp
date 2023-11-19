#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;

class LNode
{
public:
    ElemType data;
    LNode *next;

    // ���캯��
    LNode()
    {
        data = 0;
        next = NULL;
    }

    // �ӱ�β����ͷ������������L��ÿ�ξ���ͷ���֮�����Ԫ��
    static LNode* CreateListHead(int n)
    {
        LNode *L = new LNode;
        LNode *s;
        int x;
        L->next = NULL; // �Ƚ���һ����ͷ���ĵ�����
        for (int i = 0; i < n; i++)
        {
            s = new LNode; // �����½��
            cin >> x;
            s->data = x; // ����Ԫ��ֵ
            s->next = L->next;
            L->next = s; // ���뵽��ͷ
        }
        return L;
    }

    // ���������
    static void PrintList(LNode *L)
    {
        LNode *p = L->next;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    //�ϲ�������������
    // static LNode* MergeList(LNode *La, LNode *Lb)
    // {
    //     LNode *pa = La->next;
    //     LNode *pb = Lb->next;
    //     LNode *Lc = La;
    //     LNode *pc = Lc;
    //     while (pa && pb)
    //     {
    //         if (pa->data <= pb->data)
    //         {
    //             pc->next = pa;
    //             pc = pa;
    //             pa = pa->next;
    //         }
    //         else
    //         {
    //             pc->next = pb;
    //             pc = pb;
    //             pb = pb->next;
    //         }
    //     }
    //     pc->next = pa ? pa : pb;
    //     delete Lb;
    //     return Lc;
    // }

    static LNode* MergeList(LNode *La, LNode *Lb)
{
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    LNode *Lc = new LNode;
    LNode *pc = Lc;
    Lc->next = NULL;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete Lb;
    return Lc;
}

    // ���������������ͷ������ڴ�
    // ~LNode()
    // {
    //     LNode *p = this->next;
    //     while (p)
    //     {
    //         LNode *temp = p;
    //         p = p->next;
    //         delete temp;
    //     }
    // }
};

int main()
{
    int n, m;
    cout << "��������������Ԫ�ظ�����" << endl;
    cin >> n >> m;
    LNode *La = LNode::CreateListHead(n);
    LNode *Lb = LNode::CreateListHead(m);
    LNode *Lc = LNode::MergeList(La, Lb);
    cout << "�ϲ���Ϊ��" << endl;
    LNode::PrintList(Lc);
    system("pause");
    return 0;
}