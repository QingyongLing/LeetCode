#include <iostream>
using namespace std;
/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1
*/

class Solution {
public:    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    bool isBalanced(TreeNode* root) {
        return root == NULL ? true : (isBalanced(root->left) && isBalanced(root->right)
            && (abs(height(root->left) - height(root->right)) < 2));
    }
    int height(TreeNode* root) {
        if (root) {
            return max(height(root->left), height(root->right)) + 1;
        }
        else
            return 0;
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
