#include <iostream>
#include <vector>
using namespace std;
/*
A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
click to show spoilers.
Note:
Your solution should be in logarithmic complexity.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums.back() > nums[nums.size() - 2])
            return nums.size() - 1;
        return findpeak(nums, 0, nums.size() - 1);
    }
private:
    int findpeak(vector<int>& nums, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        if (lo > 0 && nums[lo + 1]<nums[lo] && nums[lo]>nums[lo - 1])
            return lo;
        if (hi < nums.size() - 1 && nums[hi + 1]<nums[hi] && nums[hi]>nums[hi - 1])
            return hi;
        if (nums[mid + 1]<nums[mid] && nums[mid]>nums[mid - 1])
            return mid;
        if (nums[mid - 1] > nums[mid])
            return findpeak(nums, lo, mid - 1);
        else
            return findpeak(nums, mid + 1, hi);
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1,2,3,1 };
    cout << s.findPeakElement(vec) << endl;
    system("pause");
    return 0;
}