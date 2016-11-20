#include <iostream>
#include <algorithm>
using namespace std;
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this 
area, called the "root." Besides the root, each house has one and only one parent house. After a tour,
the smart thief realized that "all houses in this place forms a binary tree". It will automatically 
contact the police if two directly-linked houses were broken into on the same night.
Determine the maximum amount of money the thief can rob tonight without alerting the police.
Example 1:
  3
 / \
2   3
 \   \
  3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
    3
   / \
  4   5
 / \   \
1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int rob(TreeNode* root) {
        pair<int, int> result = robbing(root);
        return max(result.first, result.second);
    }
    pair<int,int> robbing(TreeNode* root) {
        if (root == NULL) 
            return make_pair(0, 0);
        else {
            pair<int, int> left = robbing(root->left);
            pair<int, int> right = robbing(root->right);
            int first = left.second + right.second + root->val;
            int second = max(left.second + right.second, max(left.first + right.first,
                max(left.second + right.first, left.first + right.second)));
            return make_pair(first, second);
        }
    }
};
int main() {
    Solution s;
    
    return 0;
}