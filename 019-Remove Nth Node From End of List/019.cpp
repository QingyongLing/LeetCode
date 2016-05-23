/*
Given a linked list, remove the nth node from the end of list and return its head.
For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
 Given n will always be valid.
 Try to do this in one pass.

author=Ling
date=2016.5.23
*/
#include <stdio.h>
class Solution {
     struct ListNode {
          int val;
          ListNode *next;
          ListNode(int x) : val(x), next(NULL) {}
      };
 public:
   //Runtime: 4 ms
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *formernode = nullptr;
        while (temp->next != NULL)
        {
            temp = temp->next;
            if (formernode != nullptr)
                formernode = formernode->next;
            --n;
            if (n == 0)
                formernode = head;
        }
        if (formernode != nullptr)
        {
            ListNode *Nth = formernode->next;
            formernode->next = formernode->next->next;
            delete Nth;
            return head;
        }
        else
        {
            ListNode *newhead = head->next;
            delete head;
            return newhead;
        }
    }
};
