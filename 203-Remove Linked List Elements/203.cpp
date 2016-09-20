#include <iostream>
using namespace std;
/*
Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* removeElements(ListNode* head, int val) {
        ListNode helper(0);
        helper.next = head;
        ListNode* last = &helper;
        while (head != NULL) {
            if (head->val == val) {
                last->next = head->next;
                delete head;
                head = last->next;
            }else{
                last = head;
                head = head->next;
            }
        }
        return helper.next;
    }
};
int main() {
    Solution s; 
    system("pause");
    return 0;
}