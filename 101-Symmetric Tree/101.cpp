#include <iostream>
using namespace std;
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else
            return valid(root->left, root->right);
    }
    bool valid(TreeNode* leftpart, TreeNode* rightpart) {
        if (leftpart&&rightpart&&leftpart->val == rightpart->val) {
            return valid(leftpart->left, rightpart->right) && valid(leftpart->right, rightpart->left);
        }
        return !leftpart && !rightpart ? true : false;
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
