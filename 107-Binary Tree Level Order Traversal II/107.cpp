#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
   3
  / \
 9  20
   /  \
  15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        else {
            vector<int> levelnum;
            queue<TreeNode*> level;
            level.push(root);
            while (!level.empty()) {
                if (!levelnum.empty())
                    levelnum.clear();
                int num = level.size();
                while (num--) {
                    levelnum.push_back(level.front()->val);
                    if (level.front()->left)
                        level.push(level.front()->left);
                    if (level.front()->right)
                        level.push(level.front()->right);
                    level.pop();
                }
                result.push_back(levelnum);
            }
            reverse(result.begin(), result.end());
            return result;
        }
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
