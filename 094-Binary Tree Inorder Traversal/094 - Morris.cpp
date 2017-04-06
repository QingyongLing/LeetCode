#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree [1,null,2,3],
1
 \
  2
 /
3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        TreeNode *last = nullptr;
        while (root) {
            if (root->left) {
                last = root->left;
                while (last->right&&last->right != root) {
                    last = last->right;
                }
                if(last->right){
                    last->right=nullptr;
                }else{
                    last->right = root;
                    root=root->left;
                    continue;
                }
             }  
            vec.push_back(root->val);
            root = root->right;
        }
        return vec;
    }
};
int main()
{  
    Solution s;
    using Treenode = Solution::TreeNode;
    Treenode n1 = Treenode(1);
    Treenode n2 = Treenode(2);
    Treenode n3 = Treenode(3);
    Treenode n4 = Treenode(4);
    Treenode n5 = Treenode(5);
    n1.left = &n2;
    n1.right = &n5;
    n2.right = &n3;
    n3.left = &n4;
    auto result = s.inorderTraversal(&n1);
    for (auto &s : result)
    {
        cout << s << endl;
    }
    system("pause");
    return 0;
}
