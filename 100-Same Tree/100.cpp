#include <iostream>
using namespace std;
/*
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p&&q&&p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return !p && !q ? true : false;
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
