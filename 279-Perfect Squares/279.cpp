#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    //《数论导引(第5版)》([英]G.H.Hardy、E.M.Wright 著，人民邮电出版社，2008年10月第1版)第 320 页有以下定理：
    //定理 369(Lagrange 定理) : 每个正整数都是四个平方数之和
    int numSquares(int n) {
        int minnum = n / 4, start = sqrt(n);
        int first = start*start, second = 0, result = 4;
        if (first == n) return 1;
        for (int i = start; first > minnum; --i) {
            first = i*i;
            second = n - first;
            int sqrtsecond = sqrt(second);
            if (sqrtsecond*sqrtsecond == second) return 2;
            int maxj = sqrt(second / 2);
            for (int j = sqrtsecond; j >= maxj; --j) {
                int temp = sqrt(second - j*j);
                if (j*j + temp*temp == second) result = 3;
            }
        }
        return result;
    }
    int numSquares2(int n) {
        vector<int> dp(n + 1, INT_MAX);
        for (int i = 1; i <= n; ++i) {
            int num = sqrt(i);
            if (num*num == i) {
                dp[i] = 1;
            }
            else {
                for (int j = 1; j <= num; ++j)
                    dp[i] = min(dp[i - j*j] + 1, dp[i]);
            }
        }
        return dp.back();
    }
};
int main() {    
    Solution s;
    cout << s.numSquares(12) << endl;
    system("pause");
    return 0;
}