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

    //合并两个有序链表
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

    // 析构函数，用于释放链表内存
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
    cout << "请输入两个链表元素个数：" << endl;
    cin >> n >> m;
    LNode *La = LNode::CreateListHead(n);
    LNode *Lb = LNode::CreateListHead(m);
    LNode *Lc = LNode::MergeList(La, Lb);
    cout << "合并后为：" << endl;
    LNode::PrintList(Lc);
    system("pause");
    return 0;
}