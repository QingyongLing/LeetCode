#include <iostream>
#include <algorithm>
using namespace std;
/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
Example:
Input:
1
 \
 3
 /
2
Output:
1
Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        lastnum = -1;
        mindiff = INT_MAX;
        inorder(root);
        return mindiff;
    }
private:
    int lastnum, mindiff;
    void inorder(TreeNode* root) {
        if (root == NULL)return;
        if (root->left != NULL)
            inorder(root->left);
        if (lastnum == -1)
            lastnum = root->val;
        else {
            mindiff = min(mindiff, root->val - lastnum);
            lastnum = root->val;
        }
        if (root->right != NULL)
            inorder(root->right);
    }
};
int main() {
    Solution s;
    return 0;
}
