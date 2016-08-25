####以循环的方式进行中序遍历
#####不用递归的进行的话那么可以模拟递归的行为，先看递归的中序遍历：
```
1.打印左子树
2.打印自身
3.打印右子树
```
程序运行的时候相当于一直往左，将左儿子作为新的根递归，直到末端，然后将右子树当成新的根节点进行递归，之后，逐步的回退，不断将该层递归中的右子节点当成根。递归内部包含一个压栈的行为，因此可以用栈来模拟，那么我们模拟的行为是：
```
1.把节点的左儿子入栈，接着将左儿子当成根节点，继续将左儿子压栈直到左儿子为NULL
2.记录栈顶的值
3.将栈顶的节点右儿子当作新的根节点，继续上述循环
```
代码为：
```cpp
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
```
其中的：
```cpp
while (!sub.empty() && sub.top()->right == NULL) {
      result.push_back(sub.top()->val);
      sub.pop();
}
```
是用来直接添加没有右子树的节点的（不处理右子节点），不要也是可以的。








