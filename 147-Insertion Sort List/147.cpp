#include <iostream>
using namespace std;
/*
Sort a linked list using insertion sort.
*/
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}        
    };
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* nextnode = head->next, *beforenode = head;
        beforenode->next = NULL;
        while (nextnode != NULL) {
            ListNode* temp = nextnode;
            nextnode = nextnode->next;
            beforenode = insertList(beforenode, temp);
        }
        return beforenode;
    }
private:
    ListNode* insertList(ListNode* head, ListNode* node) {
        ListNode* result = head;
        if (head->val > node->val) {
            node->next = head;
            result = node;
        }else{
            while (head->next != NULL&&head->next->val <= node->val)
                head = head->next;
            ListNode* temp = head->next;
            head->next = node;
            node->next = temp;
        }
        return result;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}