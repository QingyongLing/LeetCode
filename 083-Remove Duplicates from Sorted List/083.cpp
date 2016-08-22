#include <iostream>
using namespace std;
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

class Solution {
public:
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* result = head;
        ListNode* last = head;
        head = head->next;
        while (head != NULL)
        {
            if (head->val == last->val)
            {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                last->next = head;
                last = head;
                head = head->next;
            }
        }
        last->next = NULL;
        return result;
    }

    ListNode* deleteDuplicates2(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* result = head;
        ListNode* last = head;
        head = head->next;
        while (head != NULL)
        {
            while (head != NULL&&head->val == last->val)
            {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
            if (head != NULL)
            {
                last->next = head;
                last = head;
                head = head->next;
            }
        }
        last->next = NULL;
        return result;
    }
};
int main()
{  
    Solution s;
   
    system("pause");
    return 0;
}
