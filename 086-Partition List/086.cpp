#include <iostream>
using namespace std;
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}        
    };
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return head;
        ListNode flaghead = ListNode(0);
        flaghead.next = head;
        //在nextnode后面插入小于x的节点，forward遍历链表，先跳过开始小于x的部分，然后取出小于x的节点添加到nextnode之后
        ListNode *nextnode = &flaghead, *forward = head;
        while (forward != NULL&&forward->val<x)
        {
            nextnode = forward;
            forward = forward->next;
        }
        while (1)
        {
            while (forward != NULL&&forward->next != NULL&&forward->next->val >= x)
                forward = forward->next;
            if (forward != NULL&&forward->next != NULL)
            {
                ListNode * temp = nextnode->next;
                nextnode->next = forward->next;
                forward->next = forward->next->next;
                nextnode = nextnode->next;
                nextnode->next = temp;
            }
            else
                break;
        }
        return flaghead.next;
    }
     
};
int main()
{  
    Solution s;
    
    system("pause");
    return 0;
}
