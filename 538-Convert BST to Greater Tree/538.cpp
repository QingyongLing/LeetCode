#include <iostream>
using namespace std;
/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to 
the original key plus sum of all keys greater than the original key in BST.
Example:
Input: The root of a Binary Search Tree like this:
   5
 /   \
2     13
Output: The root of a Greater Tree like this:
    18
  /   \
20     13
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL)return NULL;
        vector<int> vec;
        inorder(root, vec);
        int sum = 0;
        for (int i = vec.size() - 1; i>-1; --i) {
            sum += vec[i];
            vec[i] = sum;
        }
        int index = 0;
        settree(root, vec, index);
        return root;
    }
    void inorder(TreeNode* root, vector<int> &vec) {
        if (root == NULL)return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    void settree(TreeNode* root, vector<int> &vec, int &index) {
        if (root == NULL)return;
        settree(root->left, vec, index);
        root->val = vec[index++];
        settree(root->right, vec, index);
    }
};

int main() {
    Solution s;
    return 0;
}