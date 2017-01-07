﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a non-empty integer array, find the minimum number of moves required to make all array
elements equal, where a move is incrementing a selected element by 1 or decrementing a selected
element by 1.
You may assume the array's length is at most 10,000.
Example:
Input:
[1,2,3]
Output:
2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums[nums.size() / 2], result = 0;
        for (int i : nums) result += abs(i - n);
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 1,2,3 };
    cout << s.minMoves2(vec) << endl;
}
