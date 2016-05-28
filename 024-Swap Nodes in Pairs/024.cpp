/*
Given a linked list, swap every two adjacent nodes and return its head.
For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

author=Ling
date=2016.5.28
*/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode nothing=ListNode(0);
        ListNode *p = &nothing;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *result = second;
        while (1)
        {
            ListNode *temp = second->next;
            p->next = second;
            second->next = first;
            first->next = NULL;
            p = first;
            if (temp != NULL)
            {
                first = temp;
                second = first->next;
                if (second == NULL)
                {
                    p->next = temp;
                    break;
                }
            }
            else
                break;
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    using ListNode=Solution::ListNode;
    Solution s;
    ListNode a[] = { -2, -1, 0, 2 };
    for (auto i = begin(a); i < end(a) - 1; ++i)
    {
        i->next = i + 1;
    }
    auto result=s.swapPairs(a);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
