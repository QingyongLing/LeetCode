#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return findtarget(nums, target, 0, nums.size() - 1);
    }
    bool findtarget(vector<int> &nums, int target, int left, int right)
    {
        if (left == right)
            return nums[left] == target;
        int mid;
        if (nums[left] == nums[right])
        {
            mid = (left + right) / 2;
            return findtarget(nums, target, left, mid) || findtarget(nums, target, mid + 1, right);
        }
        else if (nums[left] < nums[right])
        {
            return binary_search(nums.begin() + left, nums.begin() + right + 1, target);
        }
        else
        {
            do {
                mid = (left + right) / 2;
                if (nums[mid] >= nums[left])
                    left = mid;
                else
                    right = mid;
            } while (left + 1 < right);
            return binary_search(nums.begin(), nums.begin() + left + 1, target) || binary_search(nums.begin() + right, nums.end(), target);
        }
    }
};
int main()
{  
    Solution s;
    vector<int> vec = { 1,3,1,1 };
    cout << (s.search(vec, 3) ? "true" : "false") << endl;
    system("pause");
    return 0;
}
