#include <iostream>
#include <vector>
using namespace std;
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        vector<int> v1, v2;
        while (l1)v1.push_back(l1->val), l1 = l1->next;
        while (l2)v2.push_back(l2->val), l2 = l2->next;
        bool add = false;
        ListNode beforehead(0), *cur = NULL;
        for (int i = v1.size() - 1, j = v2.size() - 1; i >= 0 || j >= 0;) {
            int num = add ? 1 : 0;
            if (i >= 0)num += v1[i--];
            if (j >= 0)num += v2[j--];
            if (num >= 10)num = num - 10, add = true;
            else add = false;
            beforehead.next = new ListNode(num);
            beforehead.next->next = cur;
            cur = beforehead.next;
        }
        if (add)beforehead.next = new ListNode(1), beforehead.next->next = cur;
        return beforehead.next;
    }
};
int main() {
    Solution s;
    
}
