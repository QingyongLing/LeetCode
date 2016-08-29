#include <iostream>
using namespace std;
/*
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
•You may only use constant extra space.
For example,
Given the following binary tree,
    1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:
     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
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
            TreeLinkNode *before = root1;
            TreeLinkNode *next = root2;
            TreeLinkNode *nextlevelleft = nextlevel(before), *nextlevelright = nextlevel(next);
            if (nextlevelleft&&nextlevelright) {
                connecttwotree(nextlevelleft, nextlevelright);
            }
            connecttwonode(root1, root2);
        }
    }
    TreeLinkNode *nextlevel(TreeLinkNode * root) {
        while (root) {
            if (root->left) {
                return root->left;
            }
            if (root->right) {
                return root->right;
            }
            root = root->next;
        }
        return NULL;
    }
    void connecttwonode(TreeLinkNode *left, TreeLinkNode *right) {
        if (left&&right) {
            while (left->next)
                left = left->next;
            left->next = right;
        }
    }

    void connect2(TreeLinkNode *root) {
        if (root) {
            connect2(root->left);
            connect2(root->right);
            connecttwotree2(root->left, root->right);
        }
    }
    void connecttwotree2(TreeLinkNode *root1, TreeLinkNode *root2) {
        if (root1&&root2) {
            if (root1->next == NULL)
                root1->next = root2;
            connecttwotree2(root1->right, root2->left);
            connecttwotree2(root1->right, root2->right);
            connecttwotree2(root1->left, root2->left);
            connecttwotree2(root1->left, root2->right);
        }
    }
};
int main()
{  
    Solution s;
    
    system("pause");
    return 0;
}
