####已知前序遍历和中序遍历恢复二叉树
先写个范例：
```
         4
        / \
       5   8
      /\   /\
     3 2  7  1
      \ \   /
      6  9 11
```
那么前序遍历是4 5 3 6 2 9 8 7 1 11        
那么中序遍历是3 6 5 2 9 4 7 8 11 1        
前序遍历的特点是：根节点+左子树+右子树        
中序遍历的特点是：左子树+根节点+右子树        
那么我们可以从前序遍历找到根节点，然后再在中序遍历中找出该节点，然后再该节点的左边是左子树，右边是右子树，根据左子树和右子树的长度可以对前序遍历进行划分，得出前序遍历中的左子树和右子树部分，再用前序遍历和中序遍历的左右部分分别递归。代码如下：
```cpp
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
```