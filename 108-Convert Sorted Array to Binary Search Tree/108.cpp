#include <iostream>
#include <vector>
using namespace std;
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return nums.empty() ? NULL : subtree(nums, 0, nums.size() - 1);
    }
    TreeNode* subtree(vector<int>& nums, int left, int right) {
        if (left == right)
            return new TreeNode(nums[left]);
        else {
            int mid = (left + right) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            if (mid > left)
                root->left = subtree(nums, left, mid - 1);
            if (right > mid)
                root->right = subtree(nums, mid + 1, right);
            return root;
        }
    }
};
int main()
{  
    Solution s;
    system("pause");
    return 0;
}
