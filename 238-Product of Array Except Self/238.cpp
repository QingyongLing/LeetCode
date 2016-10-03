#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeronum = 0;
        for (auto n : nums) {
            if (n == 0) ++zeronum;
            else product *= n;
        }
        vector<int> result(nums.size(), 0);
        if (zeronum > 1)
            return result;
        else if (zeronum == 1)
            result[find(nums.begin(), nums.end(), 0) - nums.begin()] = product;
        else
            for (int i = 0; i < nums.size(); ++i)
                result[i] = product / nums[i];
        return result;
    }
};
int main() {    
    system("pause");
    return 0;
}