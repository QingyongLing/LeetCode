/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 

Author=Ling
Date=2016.6.3
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0] >= target ? 0 : 1;
        if (nums[0] > target)
            return 0;
        if (target > nums[nums.size() - 1])
            return nums.size();
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        do 
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        } while (left != right);
        return left;
    }
};
int main()
{
    Solution s;
    vector<int> v = { 1,3,5,7 };
    cout<<s.searchInsert(v, 2);
    return 0;
}