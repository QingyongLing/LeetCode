#include <iostream>
#include <vector>
using namespace std;
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return
[
[5,4,11,2],
[5,8,4,5]
]
*/

class Solution {
public:    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        findpath(result, path, root, sum);
        return result;
    }
    void findpath(vector<vector<int>>& result, vector<int> &path, TreeNode* root,int sum) {
        if (root) {
            path.push_back(root->val);
            if (root->val == sum && !root->left && !root->right) {
                result.push_back(path);
            }
            findpath(result, path, root->left, sum - root->val);
            findpath(result, path, root->right, sum - root->val);
            path.pop_back();
        }
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
