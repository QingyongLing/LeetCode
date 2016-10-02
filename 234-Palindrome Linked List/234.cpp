#include <iostream>
#include <stack>
using namespace std;
/*
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}  
    };
    bool isPalindrome(ListNode* head) {
        int len = 0, rightpart = 0, mid = 0;
        ListNode* temp = head, *left = head, *right = NULL;
        while (temp != NULL) {
            ++len;
            temp = temp->next;
        }
        if (len < 2) return true;
        mid = len / 2;
        rightpart = len - mid;
        temp = head;
        while (--rightpart)
            left = left->next;
        right = left->next;
        right = reverse(right);
        ListNode* tempright = right;
        bool result = true;
        while (mid--) {
            if (temp->val != tempright->val) {
                result = false;
                break;
            }
            temp = temp->next;
            tempright = tempright->next;
        }
        left->next = reverse(right);
        return result;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode *last = NULL, *next = NULL;
        while (head->next != NULL) {
            next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        head->next = last;
        return head;
    }
};
int main() {    
    system("pause");
    return 0;
}