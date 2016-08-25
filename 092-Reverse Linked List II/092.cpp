#include <iostream>
using namespace std;
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

*/

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}        
    };
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m == n)
            return head;            
        ListNode *beforn_m = NULL;
        ListNode *pointer_m = head, *pointer_n = head;
        while (1)
        {
            if (--m > 0)
            {
                beforn_m = pointer_m;
                pointer_m = pointer_m->next;
            }
            if (--n > 0)
                pointer_n = pointer_n->next;            
            if (m <= 0 && n <= 0)
                break;
        }        
        while (pointer_m != pointer_n)
        {
            ListNode *temp = pointer_n->next;
            pointer_n->next = pointer_m;
            pointer_m = pointer_m->next;
            pointer_n->next->next = temp;
        }
        if (beforn_m != NULL)
        {
            beforn_m->next = pointer_n;
            return head;
        }
        else
            return pointer_n;
    }
};
int main()
{  
    Solution s;
    
    system("pause");
    return 0;
}
