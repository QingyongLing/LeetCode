#include <iostream>
using namespace std;
/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}        
    };
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return head;
        int len = 0;
        ListNode* temp = head;
        while (temp!=NULL) {
            temp = temp->next;
            ++len;
        }
        return sort(head, len);
    }
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode temp(0);
        ListNode* cur = &temp;
        while (head1 != NULL&&head2 != NULL) {
            if (head1->val <= head2->val) {
                cur->next = head1;
                head1 = head1->next;
            }else{
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        cur->next = head1 == NULL ? head2 : head1;
        return temp.next;
    }
    ListNode* sort(ListNode* head, int len) {
        if (len == 1) {
            head->next = NULL;
            return head;
        }else{
            int mid = len / 2;
            int left = mid;
            ListNode* temp = head;
            while (--mid) {
                temp = temp->next;
            }
            ListNode* right = temp->next;
            temp->next = NULL;
            head = sort(head, left);
            right = sort(right, len - left);
            return merge(head, right);
        }
    }
};
int main() {
    Solution s;
    Solution::ListNode l1(2),l2(1);
    l1.next = &l2;
    s.sortList(&l1);
    system("pause");
    return 0;
}