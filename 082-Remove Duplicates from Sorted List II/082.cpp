#include <iostream>
using namespace std;
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        ListNode* result = NULL;
        ListNode* resultnext = NULL;
        ListNode* temp = NULL;
        while (head != NULL)
        {
            if ((head != NULL&&head->next == NULL) || (head != NULL&&head->next != NULL&&head->val != head->next->val))
            {
                if (result == NULL)
                {
                    resultnext = result = head;
                }
                else
                {
                    resultnext->next = head;
                    resultnext = head;
                }
                head = head->next;
            }
            else if (head != NULL&&head->next != NULL&&head->val == head->next->val)
            {
                while (head != NULL&&head->next != NULL&&head->val == head->next->val)
                {
                    temp = head;
                    head = head->next;
                    delete temp;
                }
                temp = head;
                head = head->next;
                delete temp;
            }
        }
        if (resultnext != NULL)
            resultnext->next = NULL;
        return result;
    }
};
int main()
{  
    Solution s;
   
    system("pause");
    return 0;
}
