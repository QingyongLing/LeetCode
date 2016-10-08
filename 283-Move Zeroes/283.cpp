#include <iostream>
#include <vector>
using namespace std;
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
1.You must do this in-place without making a copy of the array.
2.Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0)
                nums[index++] = nums[i];
        }
        for (int i = index; i < nums.size(); ++i)
            nums[i] = 0;
    }
};
int main() {    
    Solution s;
    vector<int> vec = { 0, 1, 0, 3, 12 };
    s.moveZeroes(vec);
    for (auto &n : vec)
        cout << n << " ";
    system("pause");
    return 0;
}