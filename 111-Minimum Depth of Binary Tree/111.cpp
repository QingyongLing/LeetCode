#include <iostream>
#include <algorithm>
using namespace std;
/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

class Solution {
public:    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    int minDepth(TreeNode* root) {
        if (root) {
            if (root->left&&root->right)
                return min(minDepth(root->left), minDepth(root->right)) + 1;
            else if (root->left)
                return minDepth(root->left) + 1;
            else if (root->right)
                return minDepth(root->right) + 1;
            else
                return 1;
        }
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
