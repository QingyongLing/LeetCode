#include <iostream>
using namespace std;
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)  return NULL;
        ListNode *onestep = head, *twostep = head;
        while (twostep->next != NULL&&twostep->next->next != NULL) {
            onestep = onestep->next;
            twostep = twostep->next->next;
            if (onestep == twostep) {
                while (onestep != head) {
                    onestep = onestep->next;
                    head = head->next;
                }
                return head;
            }
        }
        return NULL;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}