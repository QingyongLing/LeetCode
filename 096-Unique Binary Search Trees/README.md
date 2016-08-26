####给定1-n的n个整数，求这些整数产生的不同二叉搜索树的数目
#####动态规划
此题的关键是分类讨论，我们用根节点来看，左子树都小于根节点，右子树都大于根节点，那么左子树的种类个数乘以右子树的种类个数就是一某一值为根节点的二叉搜索树的种类个数。把所有的节点都当做根节点进行种类个数求和可以得出结果。
代码为：
```cpp
class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp.back();
    }
};
```