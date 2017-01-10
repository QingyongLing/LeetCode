#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given an unsorted integer array, find the first missing positive integer.
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) nums[i] = INT_MAX;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (abs(nums[i]) <= nums.size()) {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) 
                return i + 1;
        }
        return nums.size() + 1;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 1 };
    cout << s.firstMissingPositive(vec) << endl;
}
