#include <iostream>
#include <vector>
using namespace std;
/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.
Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
1.The length of the given array is positive and will not exceed 20.
2.The sum of elements in the given array will not exceed 1000.
3.Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty())return 0;
        int count = 0;
        backtracking(nums, nums.size() - 1, S, count);
        return count;
    }
private:
    void backtracking(vector<int> &nums, int cur, int target, int &count) {
        if (cur == 0) {
            if (nums[cur] == target)++count;
            if (-nums[cur] == target)++count;
            return;
        }
        backtracking(nums, cur - 1, target - nums[cur], count);
        backtracking(nums, cur - 1, target + nums[cur], count);
    }
};
int main() {
    Solution s;
    return 0;
}
