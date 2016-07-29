#include <iostream>
#include <vector>
using namespace std;
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false. 
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)
            return false;
        return Jump(nums, 0);
    }
    bool Jump(vector<int>& nums, int pos)
    {
        if (pos >= nums.size() - 1)
            return true;
        int ability = nums[pos];
        int temp = 0;
        int nextpos = pos;
        for (int i = 1; i <= ability; ++i)
        {
            if (nums[pos + i] + i > temp)
            {
                nextpos = pos + i;
                temp = nums[pos + i] + i;
            }
        }
        if (pos == nextpos)
            return false;
        else
            return Jump(nums, nextpos);
    }
};
int main()
{  
    Solution s;
    //vector<int> vec = { 2,3,1,1,4 };
    vector<int> vec = { 3,2,1,0,4 };
    auto result = s.canJump(vec);  
    cout << result << endl;
    system("pause");
    return 0;
}
