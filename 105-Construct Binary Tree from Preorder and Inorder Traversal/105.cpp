#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        if (preorder.empty() || inorder.empty())
            return root;
        else
            return buildsubtree(index,preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildsubtree(unordered_map<int, int> &indexmap,vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright) {
        int index = indexmap[preorder[preleft]];
        TreeNode* root = new TreeNode(preorder[preleft]);
        if (index > inleft)
            root->left = buildsubtree(indexmap,preorder, preleft + 1, preleft + index - inleft, inorder, inleft, index - 1);
        if (index < inright)
            root->right = buildsubtree(indexmap,preorder, preleft + index - inleft + 1, preright, inorder, index + 1, inright);
        return root;
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
