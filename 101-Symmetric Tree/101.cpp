#include <iostream>
#include <stack>
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
    //循环方式实现
    bool isSymmetric2(TreeNode* root) {
        if (!root)
            return true;
        else {
            stack<TreeNode*> leftpart, rightpart;
            TreeNode* left = root->left, *right = root->right;
            while (1) {
                while (left) {
                    leftpart.push(left);
                    left = left->left;
                }
                while (right) {
                    rightpart.push(right);
                    right = right->right;
                }
                if (leftpart.empty() && rightpart.empty())
                    return true;
                else if (leftpart.empty() || rightpart.empty())
                    return false;
                //此处的size是为了保证结构一致防止这种情况：
                //     1
                //    / \
                //   2   3
                //  /   /
                // 3   2
                else if (leftpart.size() != rightpart.size())
                    return false;
                else {
                    if (leftpart.top()->val == rightpart.top()->val) {
                        left = leftpart.top()->right;
                        right = rightpart.top()->left;
                        leftpart.pop();
                        rightpart.pop();
                    }
                    else
                        return false;
                }
            }
        }
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
