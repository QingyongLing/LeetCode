/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

Author=Ling
Date=2016.6.1
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
         if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int mid = 0, left = 0, right = nums.size() - 1;
        do
        {
            mid = (left + right) / 2;
            if (nums[mid] < nums[left])
                right = mid;
            else
                left = mid;
        } while (left + 1 != right);
        auto binary_search_ = [&nums](int l, int r,int tar)
        {
            int m = 0;
            while (l < r)
            {
                m = (l + r) / 2;
                if (nums[m]<tar)
                    l = m + 1;
                else
                    r = m;
            }            
            return l;
        };
        int index = binary_search_(0, left, target);
        if (nums[index] == target)
            return index;
        index = binary_search_(right, nums.size()-1, target);
        if (nums[index] == target)
            return index;
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> v = { 5,1,3 };
    cout<<s.search(v, 3);
    return 0;
}