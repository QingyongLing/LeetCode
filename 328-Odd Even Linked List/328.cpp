#include <iostream>
using namespace std;
/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/
class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* result = head, *odd = head, *next = NULL, *even = NULL;
        if (odd->next == NULL)
            return result;
        else
            next = even = odd->next;
        while (1) {
            if (even->next != NULL) {
                odd->next = even->next;
                odd = odd->next;
            }
            else
                break;
            if (odd->next != NULL) {
                even->next = odd->next;
                even = even->next;
            }
            else {
                even->next = NULL;
                break;
            }
        }
        odd->next = next;
        return result;
    }
};
int main() {
    Solution s;
    return 0;
}