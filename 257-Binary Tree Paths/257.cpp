#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:
["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string str;
        if (root != NULL)
            binaryTreePathsimpl(root, str, result);
        return result;
    }
private:
    void binaryTreePathsimpl(TreeNode* root, string &str, vector<string>& result) {
        int size = str.size();
        str.append(to_string(root->val));
        if (root->left == NULL&&root->right == NULL)
            result.push_back(str);
        else {
            str.append("->");
            if (root->left != NULL)
                binaryTreePathsimpl(root->left, str, result);
            if (root->right != NULL)
                binaryTreePathsimpl(root->right, str, result);
        }
        str.erase(str.begin() + size, str.end());
    }
};
int main() {    
    Solution s;
   
    system("pause");
    return 0;
}