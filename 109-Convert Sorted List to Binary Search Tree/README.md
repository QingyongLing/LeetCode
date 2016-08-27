####已排序的链表生成平衡的二叉搜索树
#####参照数组的做法
此处链表不能直接用下标，因此我们用一个left节点指针和总长度表示，例如：
```
长度  根节点序号（从1开始）
 1     1
 2     1
 3     2
 4     2
```
因此我们在求中间的根节点时要采用（num+1)/2的方式获取正确的下标，那么左子树在链表的长度为mid-1，右子树在链表的长度为num-mid。代码为：
```cpp
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}        
    };
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}        
    };
    TreeNode* sortedListToBST(ListNode* head) {
        int num = 0;
        ListNode* temp = head;
        while (temp) { 
            ++num;
            temp = temp->next;
        }
        return head == NULL ? NULL : subtree(head, num);
    }
    TreeNode* subtree(ListNode* left, int num) {
        if (num == 1) {
            return new TreeNode(left->val);
        }
        else {
            int mid = (num + 1) / 2;
            int temp = mid;
            ListNode* midnode = left;
            while (--temp)
                midnode = midnode->next;
            TreeNode* root = new TreeNode(midnode->val);
            if (mid - 1 > 0)
                root->left = subtree(left, mid - 1);
            if (num - mid > 0)
                root->right = subtree(midnode->next, num - mid);
            return root;
        }
    }
};
```
我们先算出长度再，依次递归得出结果。其中midnode是用作根节点的链表中的节点的指针。