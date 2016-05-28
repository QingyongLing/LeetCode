/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
 Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Author=Ling
Date=2016.5.28
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //32ms
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int index = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
                nums[index++] = nums[i];
        }
        return index;
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vec={-1,-1,0,0,1,1,1,2,3,3,4,4};
    int index=s.removeDuplicates(vec);
    for(int i=0;i<index;++i)
        cout<<vec[i]<<"  ";
    return 0;
}
