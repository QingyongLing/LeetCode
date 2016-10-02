#include <iostream>
using namespace std;
/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
Hint:
1.Try to utilize the property of a BST.
2.What if you could modify the BST node's structure?
3.The optimal runtime complexity is O(height of BST).
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0, val = 0;
        kthSmallestimpl(root, k, cur, val);
        return val;
    }
private:
    void kthSmallestimpl(TreeNode* root, int k, int &cur,int &val) {
        if (cur >= k)
            return;
        if (root != NULL) {
            kthSmallestimpl(root->left, k, cur, val);
            if (++cur == k) 
                val = root->val;
            kthSmallestimpl(root->right, k, cur, val);
        }
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}