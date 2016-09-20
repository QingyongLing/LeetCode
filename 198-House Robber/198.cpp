#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional
test cases.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.front();
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i < 2)
                dp[i] = nums[i];
            else if (i == 2)
                dp[i] = nums[i] + dp[0];
            else
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        }
        return max(dp.back(), dp[dp.size() - 2]);
    }
};
int main() {
    Solution s;  
    system("pause");
    return 0;
}