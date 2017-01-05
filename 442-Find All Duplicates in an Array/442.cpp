#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = abs(nums[i]) - 1;
            if (nums[temp] <= 0)result.push_back(temp + 1);
            nums[temp] = -nums[temp];
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 4,3,2,7,8,2,3,1 };
    for (int i : s.findDuplicates(vec))
        cout << i << "  ";
}
