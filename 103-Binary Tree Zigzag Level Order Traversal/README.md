####ZigZag形输出二叉树
#####双向队列
对于二叉树可以将树丛根到叶子分为1到N层，分别是奇数层和偶数层，将一层的子节点全部按照从左到右的方式放在队列中，那么奇数层需要的是从左到右打印，偶数层需要的是从右到左打印，因此奇数层前面出队，同时将子节点按照先左后右的方式从后入队，偶数层从后面出队，将子节点按照先右后左的形式从前入队。代码为：
```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root)
        return result;
    else {
        vector<int> levelnum;
        deque<TreeNode*> level;
        bool oddlevel = false;
        level.push_back(root);
        while (!level.empty()) {
            if (!levelnum.empty())
                levelnum.clear();
            int num = level.size();
            oddlevel = !oddlevel;
            while (num--) {                    
                if (oddlevel) {
                    levelnum.push_back(level.front()->val);
                    if (level.front()->left)
                        level.push_back(level.front()->left);
                    if (level.front()->right)
                        level.push_back(level.front()->right);
                    level.pop_front();
                }else{
                    levelnum.push_back(level.back()->val);
                    if (level.back()->right)
                        level.push_front(level.back()->right);
                    if (level.back()->left)
                        level.push_front(level.back()->left);
                    level.pop_back();
                }                   
            }
            result.push_back(levelnum);
        }
        return result;
    }
}
```