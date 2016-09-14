#include <iostream>
using namespace std;
/*
Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *before = head;
        while (head->next != NULL&&head->next->next != NULL) {
            before = before->next;
            head = head->next->next;
            if (before == head)
                return true;
        }
        return false;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}