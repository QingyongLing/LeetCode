#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
Note: This is an extension of House Robber.
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.front();
        if (nums.size() == 2) return max(nums.front(), nums.back());
        vector<int> dp0(nums.size(), 0), dp1(nums.size(), 0);
        dp(nums, dp0, 0, nums.size() - 2);
        dp(nums, dp1, 1, nums.size() - 1);
        return max(max(dp0[dp0.size() - 2], dp0[dp0.size() - 3]), max(dp1[dp1.size() - 1], dp1[dp1.size() - 2]));
    }
private:
    void dp(vector<int>& nums, vector<int>& vec, int lo, int hi) {
        for (int i = lo; i <= hi; ++i) {
            if (i - lo < 2)
                vec[i] = nums[i];
            else if (i - lo == 2)
                vec[i] = nums[i] + vec[i - 2];
            else
                vec[i] = max(vec[i - 2], vec[i - 3]) + nums[i];
        }
    }
};
int main() {
    Solution s; 
    vector<int> vec = { 4,1,2,7,5,3,1 };
    cout << s.rob(vec) << endl;
    system("pause");
    return 0;
}