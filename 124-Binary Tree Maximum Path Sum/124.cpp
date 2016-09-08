#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
For example:
Given the below binary tree,
  1
 / \
2   3
Return 6.
*/
class Solution {
public:
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    struct pairnum {
        //maxinum path sum of subtree
        int maximum;
        //maxinum path sum of a path to root
        int maxpathnum;
        pairnum(int m, int n) :maximum(m), maxpathnum(n) {}
    };
    int maxPathSum(TreeNode* root) {
        pairnum result = findmaxinum(root);
        return result.maximum;
    }
    pairnum findmaxinum(TreeNode* root) {
        if (root == NULL)
            return pairnum(INT_MIN, INT_MIN);
        pairnum left = findmaxinum(root->left);
        pairnum right = findmaxinum(root->right);
        pairnum result(0, 0);
        int temp = root->val;
        if (left.maxpathnum>0 && right.maxpathnum>0)
            temp += left.maxpathnum + right.maxpathnum;
        result.maxpathnum = max(0, max(left.maxpathnum, right.maxpathnum)) + root->val;
        result.maximum = max(max(max(left.maximum, right.maximum), temp), result.maxpathnum);
        return result;
    }
};
int main() {
    Solution s;
    
    system("pause");
    return 0;
}