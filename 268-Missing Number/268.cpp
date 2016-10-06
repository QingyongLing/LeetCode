#include <iostream>
#include <vector>
using namespace std;
/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int minnum = nums[0], maxnum = nums[0], result = 0;
        for (auto n : nums) {
            if (n < minnum) minnum = n;
            if (n > maxnum) maxnum = n;
        }
        if (maxnum - minnum == nums.size() - 1)
            return minnum == 0 ? (maxnum + 1) : 0;
        for (auto n : nums)
            result ^= n;
        for (int i = minnum; i <= maxnum; ++i)
            result ^= i;
        return result;
    }
};
int main() {    
    Solution s;
    vector<int> vec{ 0,1,3 };
    cout << s.missingNumber(vec) << endl;
    system("pause");
    return 0;
}