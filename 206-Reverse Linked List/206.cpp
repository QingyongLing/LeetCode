#include <iostream>
using namespace std;
/*
Reverse a singly linked list.
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        return last;
    }
    //recursively
    ListNode* reverseList2(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* next = head->next;
        ListNode* newhead = reverseList2(next);
        head->next = NULL;
        next->next = head;
        return newhead;
    }
};
int main() {
    Solution s; 
    system("pause");
    return 0;
}