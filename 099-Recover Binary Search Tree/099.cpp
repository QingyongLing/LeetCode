#include <iostream>
#include <vector>
using namespace std;
/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ilegal;
        TreeNode *last = NULL;
        inorderimpl(root, last, ilegal);
        if (ilegal.size() == 2)
            swap(ilegal[0]->val, ilegal[1]->val);
        else if (ilegal.size() == 4)
            swap(ilegal[0]->val, ilegal[3]->val);
    }
private:
    TreeNode* inorderimpl(TreeNode* root, TreeNode* last, vector<TreeNode*> &vec) {
        if (root->left)
            last = inorderimpl(root->left, last, vec);
        if (last&&last->val > root->val) {
            vec.push_back(last);
            vec.push_back(root);
        }
        last = root;
        if (root->right)
            last = inorderimpl(root->right, last, vec);
        return last;
    }
};
int main() {
    Solution s;
    
}
