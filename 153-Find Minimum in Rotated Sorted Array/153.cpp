#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        return min(nums[0], findmin(nums, 0, nums.size() - 1));
    }
private:
    int findmin(vector<int>& nums, int lo, int hi) {
        if (hi - lo == 1)
            return nums[hi];
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[lo])
            return findmin(nums, mid, hi);
        else
            return findmin(nums, lo, mid);
    }
};
int main() {
    Solution s;
    vector<int> vec = { 4, 5 ,6 ,7 ,0 ,1 ,2 };
    cout << s.findMin(vec) << endl;
    system("pause");
    return 0;
}