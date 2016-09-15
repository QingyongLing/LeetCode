#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
*/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}      
    };
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        if (root == NULL)
            return result;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* temp = nodes.top();
            nodes.pop();
            result.push_back(temp->val);
            if (temp->right)
                nodes.push(temp->right);
            if (temp->left)
                nodes.push(temp->left);
        }
        return result;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}