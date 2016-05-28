/*
Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example:
 Given input array nums = [3,2,2,3], val = 3
Your function should return length = 2, with the first two elements of nums being 2.

Author=Ling
Date=2016.5.28
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            while (nums[left] != val&&left<right)
            {
                ++left;
            }
            while (nums[right] == val&&left<right)
            {
                --right;
            }
            if (left == right)
                break;
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            ++left;
            --right;
        }
        //the left of nums[right] is legal the right of nums[right] is useless,but we don't know nums[right]
        return nums[right] == val ? right : right + 1;
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vec = { 0, 1, 2, 0, -1, 0, -2, 2 };
    int index = s.removeElement(vec, 0);
    for (int i = 0; i < index; ++i)
        cout << vec[i] << " ";
    return 0;
}
