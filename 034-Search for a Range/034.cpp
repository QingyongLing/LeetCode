/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

Author=Ling
Date=2016.6.2
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = { -1, -1 };
        if (nums.size() == 0)
            return result;
        if (nums.size() == 1)
            return nums[0] == target ? (result[0] = result[1] = 0, result) : result;
        auto binary_search_ = [&nums](int left, int right,int tar, bool (*com)(int &a,int& b))->int
        {
            int mid = 0;
            do
            {
                mid = (left + right) / 2;
                if (com(nums[mid], tar))
                    left = mid;
                else
                    right = mid;
            } while (left + 1 < right);
            return nums[left] == tar ? left : right;
        };
        auto smaller = [](int &a, int &b)->bool {return a < b; };
        auto smallerandequal = [](int &a, int &b)->bool {return a <= b; };
        int index = 0;
        if (nums[index] != target)
            index = binary_search_(0, nums.size() - 1, target, smaller);
        if (nums[index] == target)
        {
            result[0] = index;
            if (result[0] == nums.size() - 1)
                result[1] = result[0];
            else if (nums[nums.size()-1]==target)
                result[1] = nums.size() - 1;
            else
                result[1] = binary_search_(0, nums.size() - 1, target, smallerandequal);
            return result;
        }
        else return result;

    }
};
int main()
{
    Solution s;
    vector<int> v = { 2,2 };
    auto result = s.searchRange(v, 2);
    for (auto &c : result)
        cout << c << " ";
    return 0;
}
