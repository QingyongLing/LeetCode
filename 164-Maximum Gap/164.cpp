#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)return 0;
        int maxnum = nums[0], minnum = nums[0];
        for (auto n : nums) {
            maxnum = max(maxnum, n);
            minnum = min(minnum, n);
        }
        int len = (maxnum - minnum) / nums.size() + 1, last = nums.size() - 1;
        vector<vector<int>> vec(nums.size());
        for (auto n : nums) {
            int index = (n - minnum) / len;
            if (vec[index].empty()) {
                vec[index].push_back(n);
                vec[index].push_back(n);
                last = min(last, index);
            }
            else {
                vec[index][0] = min(vec[index][0], n);
                vec[index][1] = max(vec[index][1], n);
            }
        }
        int result = 0;
        for (int i = last + 1; i < vec.size(); ++i) {
            if (!vec[i].empty()) {
                result = max(vec[i][0] - vec[last][1], result);
                last = i;
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 11,12,1,1,2,3,5 };
    cout << s.maximumGap(vec) << endl;
    return 0;
}
