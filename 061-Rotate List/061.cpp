#include <iostream>
using namespace std;

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}      
    };
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        int len = 1;
        ListNode* temp = head;
        while (temp->next != NULL)
        {
            ++len;
            temp = temp->next;
        }
        k %= len;
        if (k == 0)
            return head;
        temp->next = head;
        int num = len - k;
        temp = head;
        while (num > 1)
        {
            --num;
            temp = temp->next;
        }
        ListNode* result = temp->next;
        temp->next = NULL;
        return result;
    }

    //two pointers
    ListNode* rotateRight2(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        ListNode *pointer1 = head, *pointer2 = NULL;
        int len = 1;
        while (pointer1->next != NULL)
        {
            if (len == k&&pointer2 == NULL)
            {
                pointer2 = head;
            }
            else if (pointer2 != NULL)
                pointer2 = pointer2->next;
            ++len;
            pointer1 = pointer1->next;
        }
        if (pointer2!= NULL)
        {
            pointer1->next = head;
            ListNode *result = pointer2->next;
            pointer2->next = NULL;
            return result;
        }
        else
        {
            k %= len;
            if (k == 0)
                return head;
            else
                return rotateRight2(head, k);
        }
    }
};


int main()
{
    Solution s;
    system("pause");
}
