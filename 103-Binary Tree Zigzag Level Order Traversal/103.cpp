#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between)
For example:
Given binary tree [3,9,20,null,null,15,7],
   3
  / \
 9  20
   /  \
  15   7
return its zigzag level order traversal as:
[
[3],
[20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        else {
            vector<int> levelnum;
            deque<TreeNode*> level;
            bool oddlevel = false;
            level.push_back(root);
            while (!level.empty()) {
                if (!levelnum.empty())
                    levelnum.clear();
                int num = level.size();
                oddlevel = !oddlevel;
                while (num--) {                    
                    if (oddlevel) {
                        levelnum.push_back(level.front()->val);
                        if (level.front()->left)
                            level.push_back(level.front()->left);
                        if (level.front()->right)
                            level.push_back(level.front()->right);
                        level.pop_front();
                    }else{
                        levelnum.push_back(level.back()->val);
                        if (level.back()->right)
                            level.push_front(level.back()->right);
                        if (level.back()->left)
                            level.push_front(level.back()->left);
                        level.pop_back();
                    }                   
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
