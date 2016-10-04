﻿#include <iostream>
#include <vector>
using namespace std;
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
1.The order of the result is not important. So in the above example, [5, 3] is also correct.
2.Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int value = 0;
        for (auto n : nums) value ^= n;
        value &= -value;
        vector<int> result(2, 0);
        for (auto n : nums)
            n&value ? result[0] ^= n : result[1] ^= n;
        return result;
    }
};
int main() {    
    Solution s;
    vector<int> vec{ 1, 2, 1, 3, 2, 5 };
    for (auto v : s.singleNumber(vec))
        cout << v << " ";
    cout << endl;
    system("pause");
    return 0;
}