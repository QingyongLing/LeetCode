#include <iostream>
#include <vector>
using namespace std;
/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:
1.You must not modify the array (assume the array is read only).
2.You must use only constant, O(1) extra space.
3.Your runtime complexity should be less than O(n2).
4.There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (hi - lo) / 2 + lo;
            int num = count(nums, mid);
            if (num <= mid)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
private:
    int count(vector<int>& nums, int target) {
        int n = 0;
        for (int i : nums)
            if (i <= target)++n;
        return n;
    }
};
int main() {   
    Solution s;
    vector<int> vec = { 1,3,4,2,2 };
    cout << s.findDuplicate(vec) << endl;
    return 0;
}