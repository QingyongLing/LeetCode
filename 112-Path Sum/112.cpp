﻿#include <iostream>
using namespace std;
/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,               
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

class Solution {
public:    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    bool hasPathSum(TreeNode* root, int sum) {
        if (root) {
            if (root->val == sum && !root->left && !root->right)
                return true;
            else
                return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        }
        else
            return false;
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
