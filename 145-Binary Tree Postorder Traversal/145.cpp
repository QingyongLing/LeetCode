#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode*> nodes;
        pushleft(nodes, root);
        TreeNode* lastpop = NULL;
        while (!nodes.empty()) {
            TreeNode* temp = nodes.top();
            if (temp->right == NULL || (temp->right != NULL&&lastpop == temp->right)) {
                result.push_back(temp->val);
                lastpop = temp;
                nodes.pop();
                continue;
            }
            else if (temp->right) {
                pushleft(nodes,temp->right);
            }
        }
        return result;
    }
private:
    void pushleft(stack<TreeNode*>& nodes, TreeNode* root) {
        while (root != NULL) {
            nodes.push(root);
            root = root->left;
        }
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}