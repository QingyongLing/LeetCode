#include <iostream>
#include <vector>
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
int main()
{  
    Solution s;
    cout << s.numTrees(3) << endl;
    system("pause");
    return 0;
}
