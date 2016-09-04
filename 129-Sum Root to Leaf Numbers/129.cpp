#include <iostream>
#include <deque>
using namespace std;
/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
  1
 / \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
*/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int sumNumbers(TreeNode* root) {
        int result = 0;
        if (root == NULL)
            return result;
        deque<TreeNode*> level;
        deque<int> nums;
        level.push_back(root);
        nums.push_back(root->val);
        while (!level.empty()) {
            int n = level.size();
            while (n--) {
                TreeNode *node = level.front();
                int numsbefore = nums.front();                 
                if (node != NULL) {                    
                    if (node->left != NULL) {
                        level.push_back(node->left);
                        nums.push_back(numsbefore * 10 + node->left->val);
                    }
                    if (node->right != NULL) {
                        level.push_back(node->right);
                        nums.push_back(numsbefore * 10 + node->right->val);
                    }
                    if (node->left == NULL&&node->right == NULL) {
                        result += numsbefore;
                    }
                }
                level.pop_front();
                nums.pop_front();
            }                     
        }
        return result;
    }
};
int main() {
    Solution s;
    using node = Solution::TreeNode;
    node n1(0);
    node n2(3);
    node n3(4);
    node n4(1);
    n1.left = &n2;
    n2.right = &n3;
    n1.right = &n4;
    cout << s.sumNumbers(&n1) << endl;
    system("pause");
    return 0;
}