#include <iostream>
using namespace std;
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}       
    };
    //1.find the right part
    //2.cut the left part and right part
    //3.reverse the right part
    //4.merge left part and right part
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            temp = temp->next;
            ++len;
        }
        if (len < 3)return;
        temp = head;
        int mid = (len + 1) / 2;
        while (--mid)
            temp = temp->next;
        ListNode* rightlist = temp->next;
        temp->next = NULL;
        rightlist = reverse(rightlist);
        merge(head, rightlist);
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* result = head1;
        while (head2 != NULL) {
            ListNode* temp = head1->next;
            head1->next = head2;
            head2 = head2->next;
            head1->next->next = temp;
            head1 = temp;
        }
        return result;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* left = NULL, *next = head->next;
        while (next != NULL) {
            head->next = left;
            left = head;
            head = next;
            next = next->next;
        }
        head->next = left;
        return head;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}