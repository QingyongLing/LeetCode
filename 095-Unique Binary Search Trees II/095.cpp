#include <iostream>
#include <vector>
using namespace std;
/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n == 0)
            return result;
        vector<vector<TreeNode*>> dp;
        dp.push_back({ NULL });
        for (int i = 1; i <= n; ++i) {
            vector<TreeNode*> temp;
            for (int j = 1; j <= i; ++j) {
                for (auto &left : dp[j - 1]) {
                    for (auto &right : dp[i - j]) {
                        TreeNode* root = new TreeNode(j);
                        root->left = CopyTree(left, 0);
                        root->right = CopyTree(right, j);
                        temp.push_back(root);
                    }
                }
            }
            dp.push_back(temp);
        }
        for (int i = 1; i < dp.size() - 1; ++i) {
            for (auto &root : dp[i])
                FreeTree(root);
        }
        return dp.back();
    }
    TreeNode* CopyTree(TreeNode* root, int incre) {
        if (root) {
            TreeNode* copyroot = new TreeNode(root->val + incre);
            copyroot->left = CopyTree(root->left, incre);
            copyroot->right = CopyTree(root->right, incre);
            return copyroot;
        }
        else
            return NULL;
    }
    void FreeTree(TreeNode* root) {
        if (root->left)
            FreeTree(root->left);
        if (root->right)
            FreeTree(root->right);
        delete root;
    }
    void Print(TreeNode* root) {
        if (root) {
            cout << root->val << " ";
            Print(root->left);           
            Print(root->right);
        }
    }
};
int main()
{  
    Solution s;
    auto result = s.generateTrees(3);
    for (auto &root : result) {
        s.Print(root);
        cout << endl;
        s.FreeTree(root);
    }
    system("pause");
    return 0;
}
