#include <iostream>
using namespace std;
/*
Given a binary tree
struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
•You may only use constant extra space.
•You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:
    1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
*/

class Solution {
public:
    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
        TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}        
    };
    void connect(TreeLinkNode *root) {
        if (root) {
            connect(root->left);
            connect(root->right);
            connecttwotree(root->left, root->right);
        }
    }
    void connecttwotree(TreeLinkNode *root1, TreeLinkNode *root2) {
        if (root1&&root2) {
            root1->next = root2;
            connecttwotree(root1->right, root2->left);
        }
    }
};
int main()
{  
    Solution s;
    
    system("pause");
    return 0;
}
