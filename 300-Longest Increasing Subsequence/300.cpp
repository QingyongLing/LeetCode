#include <iostream>
#include <vector>
using namespace std;
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.
For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (auto &n : nums) {
            if (LIS.empty() || n > LIS.back())
                LIS.push_back(n);
            else
                LIS[firstbigger(LIS, n)] = n;
        }
        return LIS.size();
    }
private:
    //>=
    int firstbigger(vector<int> &LIS,int target) {
        int lo = 0, hi = LIS.size() - 1;
        while (hi - lo > 1) {
            int mid = (hi - lo) / 2 + lo;
            if (LIS[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return LIS[lo] >= target ? lo : hi;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 10, 9, 2, 5, 3, 7, 101, 18 };
    cout << s.lengthOfLIS(vec) << endl;
    return 0;
}