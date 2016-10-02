#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
    };
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        findNode(root, path, p, q);
        int len = min(first.size(), second.size());
        for (int i = 0; i < len; ++i) {
            if (first[i] != second[i])
                return first[i - 1];
        }
        return first[len - 1];
    }
private:
    vector<TreeNode*> first;
    vector<TreeNode*> second;
    void findNode(TreeNode* root, vector<TreeNode*> &path, TreeNode* p, TreeNode* q) {
        if (root == NULL) return;
        path.push_back(root);
        if (root == p) first = path;
        if (root == q) second = path;
        findNode(root->left, path, p, q);
        findNode(root->right, path, p, q);
        path.pop_back();
    }
};
int main() {    
    system("pause");
    return 0;
}