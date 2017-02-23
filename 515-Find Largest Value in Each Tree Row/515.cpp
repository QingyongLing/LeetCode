#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
/*
You need to find the largest value in each row of a binary tree.
Example:
Input:
    1
   / \
  3   2
 / \   \
5   3   9
Output: [1, 3, 9]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> answer;
        if (root == NULL)return answer;
        deque<TreeNode*> level;
        level.push_back(root);
        while (!level.empty()) {
            int num = level.size();
            int temp = INT_MIN;
            while (num--) {
                TreeNode* p = level.front();
                temp = max(temp, p->val);
                if (p->left != NULL)
                    level.push_back(p->left);
                if (p->right != NULL)
                    level.push_back(p->right);
                level.pop_front();
            }
            answer.push_back(temp);
        }
        return answer;
    }
};
int main() {
    Solution s;
    return 0;
}
