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

    // ȡ������λ��i��Ԫ��
    static ElemType GetElem_L(LNode *L, int i, ElemType &e)
    {
        LNode *p = L->next;
        int j = 1;
        while (p && j < i)
        {
            p = p->next;
            ++j;
        }
        if (!p || j > i)
            return ERROR;
        e = p->data;
        return OK;
    }

    // �������в���һ��Ԫ��
    static ElemType ListInsert_L(LNode *L, int i, ElemType e)
    {
        LNode *p = L;
        int j = 0;
        while (p && j < i - 1)
        {
            p = p->next;
            j++;
        }
        if (!p || j > i - 1)
        {
            return ERROR;
        }
        LNode *s = new LNode;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return OK;
    }

    // �ӵ�������ɾ��һ��Ԫ��
    static ElemType ListDelete_L(LNode *L, int i)
    {
        LNode *p = L;
        int j = 0;
        while (p && j < i - 1)
        {
            p = p->next;
            j++;
        }
        if (!p || j > i - 1)
        {
            return ERROR;
        }
        LNode *q = p->next;
        p->next = q->next;
        ElemType e = q->data;
        delete q;
        return e;
    }

    // ���������������ͷ������ڴ�
//     ~LNode()
//     {
//         LNode *p = this->next;
//         while (p)
//         {
//             LNode *temp = p;
//             p = p->next;
//             delete temp;
//         }
//     }
    };

int main()
{
    int n;
    cout << "������Ԫ�ظ�����" << endl;
    cin >> n;
    LNode *L = LNode::CreateListHead(n);
    cout << "���������" << endl;
    LNode::PrintList(L);
    int i;
    cout << "������Ҫȡ��Ԫ��λ�ã�" << endl;
    cin >> i;
    ElemType e;
    if (LNode::GetElem_L(L, i, e) == OK)
    {
        cout << e << endl;
    }
    else
    {
        cout << "ȡԪ��ʧ��" << endl;
    }

    int j;
    cout << "������Ҫ�����λ�ã�" << endl;
    cin >> j;
    ElemType f;
    cin >> f;
    if (LNode::ListInsert_L(L, j, f) == OK)
    {
        cout << "����ɹ������������" << endl;
        LNode::PrintList(L);
    }
    else
    {
        cout << "����ʧ��" << endl;
    }

    int k;
    cout << "������Ҫɾ����λ�ã�" << endl;
    cin >> k;
    ElemType deleted_element = LNode::ListDelete_L(L, k);
    if (deleted_element != ERROR)
    {
        cout << "ɾ���ɹ�����ɾ����Ԫ��Ϊ��" << deleted_element << endl;
        cout << "���������" << endl;
        LNode::PrintList(L);
    }
    else
    {
        cout << "ɾ��ʧ��" << endl;
    }

    // �ͷ������ڴ�
    delete L;
    system("pause");
    return 0;
}
