#include <iostream>
using namespace std;
/*
Find the sum of all left leaves in a given binary tree.

Example:
    3
   / \
  9  20
  /  \
 15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        if (root != NULL) {
            if (root->left != NULL&&root->left->left == NULL&&root->left->right == NULL)
                result += root->left->val;
            else if (root->left != NULL)
                result += sumOfLeftLeaves(root->left);
            if (root->right != NULL)
                result += sumOfLeftLeaves(root->right);
        }
        return result;
    }
};

int main() {
    Solution s;
    
    return 0;
}