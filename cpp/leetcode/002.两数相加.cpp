#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int len1 = 1;   // l1长度
    int len2 = 1;   // l2长度

    ListNode * p = l1;
    ListNode * q = l2;

    while(p->next != NULL)
    {
        len1++;
        p = p->next;
    }

    while(q->next != NULL)
    {
        len2++;
        q = q->next;
    }

    // 短的末尾补0
    if(len1 > len2)
    {
        for(int i=1; i<= len1-len2; i++)
        {
            q->next = new ListNode(0);
            q = q->next;
        }
    }
    else
    {
        for(int i=1; i<= len2-len1; i++)
        {
            p->next = new ListNode(0);
            p = p->next;
        }
    }

    p = l1;
    q = l2;
    bool count = false;     // 记录是否进位
    ListNode * l3 = new ListNode(-1);   //存放结果
    ListNode * m = l3;      // l3的移动指针
    int ret;    //记录没位上的相加结果

    while (p != NULL && q!=NULL)
    {
        ret = count + p->val + q->val;
        m->next = new ListNode(ret % 10);

        count = (ret>=10 ? true: false);

        m = m->next;
        p = p->next;
        q = q->next;
    }

    if(count)   // 最后一位相加还有进位
    {
        m-> next = new ListNode(1);
        m = m->next;
    }

    return l3->next;
}

int main()
{
    ListNode l1;
    l1.val = 2;
    l1.next->val = 4;
    l1.next->next->val = 3;

    ListNode l2;
    l2.val = 5;
    l2.next->val = 6;
    l2.next->next->val = 4;

    ListNode * r = addTwoNumbers(&l1, &l2);
    ListNode * it = r;
    while (it != NULL)
    {
        cout << it->val << " ";
    }
    cout << endl;
    return 0;
}