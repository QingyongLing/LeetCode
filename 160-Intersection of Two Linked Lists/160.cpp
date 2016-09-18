#include <iostream>
using namespace std;
/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 → a2
                  ↘
                   c1 → c2 → c3
                  ↗
B:     b1 → b2 → b3
begin to intersect at node c1.
Notes:
•If the two linked lists have no intersection at all, return null.
•The linked lists must retain their original structure after the function returns.
•You may assume there are no cycles anywhere in the entire linked structure.
•Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}        
    };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = 1, lenB = 1;
        ListNode *tempA = headA, *tempB = headB;
        while (tempA->next != NULL){
            tempA = tempA->next;
            ++lenA;
        }
        while (tempB->next != NULL) {
            tempB = tempB->next;
            ++lenB;
        }
        if (tempA != tempB) return NULL;
        if (lenA > lenB) {
            int num = lenA - lenB;
            while (num--)
                headA = headA->next;
        }
        else if (lenA < lenB) {
            int num = lenB - lenA;
            while (num--)
                headB = headB->next;
       }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
       }
        return headA;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}