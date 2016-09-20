#include <vector>
#include <iostream>
#include <deque>
using namespace std;
/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}      
    };
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            size_t num = nodes.size();
            result.push_back(nodes.back()->val);
            while (num--) {
                TreeNode* temp = nodes.front();
                nodes.pop_front();
                if (temp->left != NULL)
                    nodes.push_back(temp->left);
                if (temp->right != NULL)
                    nodes.push_back(temp->right);
            }
        }
        return result;
    }
};
int main() {
    Solution s;  
    system("pause");
    return 0;
}