#include <iostream>
using namespace std;
/*
Given a binary tree, flatten it to a linked list in-place.
For example,
Given
    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

class Solution {
public:    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    void flatten(TreeNode* root) {
        if (root) {
            TreeNode node = TreeNode(0);
            node.right = root;
            linked(&node, root);
        }
    }
    //before指的是链表末尾待插入点的前一个节点
    TreeNode* linked(TreeNode* before, TreeNode* root) {
        TreeNode *left = root->left, *right = root->right;
        root->left = NULL;
        root->right = NULL;
        before->right = root;
        before = root;
        if (left)
            before = linked(before, left);
        if (right)
            before = linked(before, right);
        return before;
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
