#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
 /  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
