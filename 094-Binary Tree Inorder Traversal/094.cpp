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
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode*> sub;
        TreeNode* temp = root;
        while (1){
            while (temp != NULL){
                sub.push(temp);
                temp = temp->left;
            }
            //这部分while不要也可
            while (!sub.empty() && sub.top()->right == NULL) {
                result.push_back(sub.top()->val);
                sub.pop();
            }
            if (!sub.empty()) {
                temp = sub.top()->right;
                result.push_back(sub.top()->val);
                sub.pop();
            }
            else
                break;
        }
        return result;
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
