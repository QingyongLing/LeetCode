#include <iostream>
using namespace std;
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}        
    };
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    TreeNode* sortedListToBST(ListNode* head) {
        int num = 0;
        ListNode* temp = head;
        while (temp) { 
            ++num;
            temp = temp->next;
        }
        return head == NULL ? NULL : subtree(head, num);
    }
    TreeNode* subtree(ListNode* left, int num) {
        if (num == 1) {
            return new TreeNode(left->val);
        }
        else {
            int mid = (num + 1) / 2;
            int temp = mid;
            ListNode* midnode = left;
            while (--temp)
                midnode = midnode->next;
            TreeNode* root = new TreeNode(midnode->val);
            if (mid - 1 > 0)
                root->left = subtree(left, mid - 1);
            if (num - mid > 0)
                root->right = subtree(midnode->next, num - mid);
            return root;
        }
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
