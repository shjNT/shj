#include <iostream>
using namespace std;
#include <vector>

// 合并K个升序链表

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.empty()) return nullptr;
        
        ListNode * rslt = new ListNode(-1);
        ListNode * tp = rslt;
        
        while(true)
        {
            bool flag = true;
            for (int i=0; i<(int)lists.size(); i++)
            {
                if(lists[i] != nullptr)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) return rslt->next;


            ListNode * record = new ListNode(INT_MAX);
            // cout << record->val << endl;
            int idx = 0;
            for (int i = 0; i<(int)lists.size(); i++)
            {
                if(lists[i] != nullptr && lists[i]->val < record->val)
                {
                    record = lists[i];
                    idx = i;
                }
            }
            tp->next = record;
            tp = tp->next;
            // cout << lists[idx]->val << endl;

            lists[idx] = lists[idx]->next;
        }
    }
};

int main()
{
    vector<ListNode *> lists;
    ListNode * l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    lists.push_back(l1);
    ListNode * l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    // lists.push_back(l2);
    ListNode * l3 = new ListNode(2);
    l3->next = new ListNode(6);
    lists.push_back(l3);

    Solution sol;
    ListNode* res = sol.mergeKLists(lists);
    // ListNode * tpp = res;
    while(res)
    {
        cout << res->val << endl;
        res = res ->next;
    }

    return 0;
}