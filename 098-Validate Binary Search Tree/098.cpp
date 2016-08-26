#include <iostream>
#include <vector>
#include <limits>
using namespace std;
/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
•The left subtree of a node contains only nodes with keys less than the node's key.
•The right subtree of a node contains only nodes with keys greater than the node's key.
•Both the left and right subtrees must also be binary search trees.
Example 1:
  2
 / \
1   3
Binary tree [2,1,3], return true.
Example 2:
  1
 / \
2   3
Binary tree [1,2,3], return false.
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    bool isValidBST(TreeNode* root) {
        return validNode(root, INT_MIN, INT_MAX);
    }
    bool validNode(TreeNode* root, long long left, long long right) {
        if (!root)
            return true;
        else {
            if (root->val > right || root->val < left)
                return false;
            else
                return validNode(root->left, left, root->val - 1LL) && validNode(root->right, root->val + 1LL, right);
        }
    }

    bool isValidBST2(TreeNode* root) {
        return validNode2(root, INT_MIN, INT_MAX);
    }
    bool validNode2(TreeNode* root, int left, int right) {
        if (!root)
            return true;
        else {
            if (root->val > right || root->val < left)
                return false;
            else if ((root->val == INT_MIN&&root->left) || (root->val == INT_MAX&&root->right))
                return false;
            else
                return validNode2(root->left, left, root->val - 1) && validNode2(root->right, root->val + 1, right);
        }
    }
};
int main()
{  
    Solution s;
    Solution::TreeNode n1(1);
    Solution::TreeNode n2(1);
    n1.left = &n2;
    cout << (s.isValidBST2(&n1) ? "true" : "false") << endl;
    system("pause");
    return 0;
}
