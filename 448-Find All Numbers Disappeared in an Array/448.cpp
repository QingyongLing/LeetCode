﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice
and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does 
not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = abs(nums[i]) - 1;
            if (nums[temp] > 0)nums[temp] = -nums[temp];
        }
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)result.push_back(i + 1);
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 4,3,2,7,8,2,3,1 };
    for (int i : s.findDuplicates(vec))
        cout << i << "  ";
}
