#include <iostream>
using namespace std;
#include <vector>

// K 个一组翻转链表

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode * tmp = head;
        int len = 0;
        while(tmp != nullptr)
        {
            len++;
            tmp = tmp->next;
        }
        int num = len / k;

        ListNode * cur = head;
        vector<ListNode *> vec;
        ListNode * last = nullptr;
        for(int i=0; i<num; i++)
        {           
            ListNode * pre = nullptr;           
            
            int j = 0;
            while(j<k)
            {
                ListNode * nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
                j++;
                if (i == num-1) last = nxt;
            }
            ListNode * sub_head = pre;
            vec.push_back(sub_head);
            if(last) vec.push_back(last);
        }
        
        // cout << vec[1]->next->val << endl;

        for(int i=0; i<(int)vec.size()-1; i++)
        {
            ListNode * tmp = vec[i];
            while(tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = vec[i+1];
        }
        return vec[0];
    }
};

int main()
{
    Solution sol;
    ListNode * head = new ListNode(1);
    // ListNode * tmp = head;
    // for (int i = 2; i< 6; i++)
    // {
    //     tmp->next = new ListNode(i);
    //     tmp = tmp->next;
    // }
    ListNode* rslt = sol.reverseKGroup(head, 1);
    while(rslt)
    {
        cout << rslt->val << endl;
        rslt = rslt->next;
    }
    return 0;
}