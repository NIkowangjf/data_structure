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

    // 构造函数
    LNode()
    {
        data = 0;
        next = NULL;
    }

    // 从表尾到表头逆向建立单链表L，每次均在头结点之后插入元素
    static LNode* CreateListHead(int n)
    {
        LNode *L = new LNode;
        LNode *s;
        int x;
        L->next = NULL; // 先建立一个带头结点的单链表
        for (int i = 0; i < n; i++)
        {
            s = new LNode; // 生成新结点
            cin >> x;
            s->data = x; // 输入元素值
            s->next = L->next;
            L->next = s; // 插入到表头
        }
        return L;
    }

    // 输出单链表
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

    // 取单链表位置i的元素
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

    // 向单链表中插入一个元素
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

    // 从单链表中删除一个元素
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

    // 析构函数，用于释放链表内存
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
    cout << "请输入元素个数：" << endl;
    cin >> n;
    LNode *L = LNode::CreateListHead(n);
    cout << "输出单链表：" << endl;
    LNode::PrintList(L);
    int i;
    cout << "请输入要取的元素位置：" << endl;
    cin >> i;
    ElemType e;
    if (LNode::GetElem_L(L, i, e) == OK)
    {
        cout << e << endl;
    }
    else
    {
        cout << "取元素失败" << endl;
    }

    int j;
    cout << "请输入要插入的位置：" << endl;
    cin >> j;
    ElemType f;
    cin >> f;
    if (LNode::ListInsert_L(L, j, f) == OK)
    {
        cout << "插入成功，输出单链表：" << endl;
        LNode::PrintList(L);
    }
    else
    {
        cout << "插入失败" << endl;
    }

    int k;
    cout << "请输入要删除的位置：" << endl;
    cin >> k;
    ElemType deleted_element = LNode::ListDelete_L(L, k);
    if (deleted_element != ERROR)
    {
        cout << "删除成功，被删除的元素为：" << deleted_element << endl;
        cout << "输出单链表：" << endl;
        LNode::PrintList(L);
    }
    else
    {
        cout << "删除失败" << endl;
    }

    // 释放链表内存
    delete L;
    system("pause");
    return 0;
}
