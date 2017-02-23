#include <iostream>
#include <vector>
using namespace std;
/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
Assume a BST is defined as follows:
•The left subtree of a node contains only nodes with keys less than or equal to the node's key.
•The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
•Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
1
 \
  2
 /
2
return [2].
Note: If a tree has more than one mode, you can return them in any order.
Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> answer;
        if (root == NULL)return answer;
        count = 0, maxcount = 0;
        TreeNode* mini = root;
        while (mini->left != NULL)
            mini = mini->left;
        lastnum = mini->val - 1;
        inorder(root, answer);
        return answer;
    }
private:
    int count, lastnum, maxcount;
    void inorder(TreeNode* root, vector<int> &answer) {
        if (root == NULL)return;
        inorder(root->left, answer);
        if (lastnum == root->val) {
            ++count;
        }
        else {
            count = 1;
            lastnum = root->val;
        }
        if (count == maxcount)
            answer.push_back(lastnum);
        else if (maxcount < count) {
            maxcount = count;
            answer.clear();
            answer.push_back(lastnum);
        }
        inorder(root->right, answer);
    }
};
int main() {
    Solution s;
    return 0;
}
