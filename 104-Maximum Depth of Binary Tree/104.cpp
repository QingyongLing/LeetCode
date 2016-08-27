#include <iostream>
#include <algorithm>
using namespace std;
/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    int maxDepth(TreeNode* root) {
        if (root)
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
