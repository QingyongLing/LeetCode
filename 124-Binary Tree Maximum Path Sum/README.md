####给一个二叉树，找到一条和最大的路径，返回最大值
#####遍历树，递归
对于一个二叉树来说最大的路径有很多情况，题目没有要求一定要过根节点所以也可以是子树的最大值。         
那么对于一个根节点来说，最大值可能有以下几种情况：
1.左子树的最大值         
2.右子树的最大值         
3.过左子树根节点的路径和的最大值或者是过右子树根节点的路径和的最大值       
4.过左子树根节点的路径和最大值+过右子树根节点的路径和最大值+根节点的值         
那么过左子树根节点的路径最大值也可以分类：       
1.左子树根节点的值        
2.左子树根节点的值+过左子树的左子树的根节点的路径和的最大值           
3.左子树根节点的值+过左子树的右子树的根节点的路径和的最大值           
右子树也可以这样分。那么假设maximum是树的路径和的最大值，maxpathnum是过该树根节点的路径和的最大值            
```cpp
class Solution {
public:
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    struct pairnum {
        //maxinum path sum of subtree
        int maximum;
        //maxinum path sum of a path to root
        int maxpathnum;
        pairnum(int m, int n) :maximum(m), maxpathnum(n) {}
    };
    int maxPathSum(TreeNode* root) {
        pairnum result = findmaxinum(root);
        return result.maximum;
    }
    pairnum findmaxinum(TreeNode* root) {
        if (root == NULL)
            return pairnum(INT_MIN, INT_MIN);
        pairnum left = findmaxinum(root->left);
        pairnum right = findmaxinum(root->right);
        pairnum result(0, 0);
        int temp = root->val;
        if (left.maxpathnum>0 && right.maxpathnum>0)
            temp += left.maxpathnum + right.maxpathnum;
        result.maxpathnum = max(0, max(left.maxpathnum, right.maxpathnum)) + root->val;
        result.maximum = max(max(max(left.maximum, right.maximum), temp), result.maxpathnum);
        return result;
    }
};
```