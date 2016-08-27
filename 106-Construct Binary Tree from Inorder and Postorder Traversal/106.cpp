#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        if (postorder.empty() || inorder.empty())
            return root;
        else
            return buildsubtree(index, postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildsubtree(unordered_map<int, int> &indexmap,vector<int>& postorder, int postleft, int postright, vector<int>& inorder, int inleft, int inright) {
        int index = indexmap[postorder[postright]];
        TreeNode* root = new TreeNode(postorder[postright]);
        if (index > inleft)
            root->left = buildsubtree(indexmap, postorder, postleft, postleft + index - inleft - 1, inorder, inleft, index - 1);
        if (index < inright)
            root->right = buildsubtree(indexmap, postorder, postleft + index - inleft, postright - 1, inorder, index + 1, inright);
        return root;
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
