﻿#include <iostream>
#include <stack>
using namespace std;
/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
};
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushleft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return nodes.empty() ? false : true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *result = nodes.top();
        nodes.pop();
        if (result->right) {
            pushleft(result->right);
        }
        return result->val;
    }
private:
    stack<TreeNode *> nodes;
    void pushleft(TreeNode *root) {
        while (root != NULL) {
            nodes.push(root);
            root = root->left;
        }
    }
};

int main() {
    system("pause");
    return 0;
}