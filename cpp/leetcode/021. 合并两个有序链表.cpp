#include <iostream>
using namespace std;

//  合并两个有序链表

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode res(0);
        ListNode * tmp = &res;
        while(list1 != nullptr && list2 != nullptr)
        {
            
            if(list1->val <= list2->val)
            {
                tmp->next = list1;
                list1 = list1->next;
                tmp = tmp->next;
                // cout << (*tmp).val << endl;
                
            }
            else
            {
                tmp->next = list2;
                list2 = list2->next;
                tmp = tmp->next; 
                // cout << (*tmp).val << endl;              
            }
        }

        while(list1 != nullptr)
        {
            tmp->next = list1;
            // cout << (*tmp).val << endl;
            list1 = (*list1).next;
            tmp = (*tmp).next;
        }

        while(list2 != nullptr)
        {
            tmp->next = list2;
            // cout << (*tmp).val << endl;
            list2 = (*list2).next;
            tmp = (*tmp).next;
        }
        // cout << res.val << endl;
        
        return res.next;
    }
};



int main()
{
    ListNode l1(4);
    ListNode l2(2, &l1);
    ListNode l3(1, &l2);
    // cout << l3.val << endl;
    // cout << l3.next->val << endl;
    // cout << l3.next->next->val << endl;

    ListNode la(4);
    ListNode lb(3, &la);
    ListNode lc(1, &lb);

    Solution sol;
    ListNode * rslt = sol.mergeTwoLists(&l3, &lb);
    
    // cout << rslt->val << endl;

    while(rslt!= nullptr)
    {
        cout << (*rslt).val << endl;
        rslt = rslt->next;
    }
    return 0;
}