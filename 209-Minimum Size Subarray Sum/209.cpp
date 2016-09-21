#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
click to show more practice.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0] >= s ? 1 : 0;
        int lo = 0, hi = 0, sum = nums[0], minwin = INT_MAX;
        while (1) {
            if (hi == nums.size() - 1 && sum < s) 
                break;
            if (sum >= s) {
                if (hi == lo) return 1;
                minwin = min(minwin, hi - lo + 1);
                sum -= nums[lo];
                ++lo;
            }else{               
                ++hi;
                sum += nums[hi];
            }
        }
        return minwin == INT_MAX ? 0 : minwin;
    }
    int minSubArrayLen2(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0] >= s ? 1 : 0;
        int sum = 0, result = INT_MAX;
        vector<int> sumarray;       
        for (auto n : nums) {
            sumarray.push_back(sum += n);
        }
        for (int i = 0; i < sumarray.size(); ++i) {
            if (i == 0 && sumarray[i] >= s) 
                return 1;
            if (sumarray[i] == s) {
                result = min(result, i + 1);
            }
            if (sumarray[i] > s) {
                int index = binary_search(sumarray, sumarray[i] - s, 0, i - 1);
                if (index != -1) {
                    result = min(result, i - index);
                }
            }
        }
        return result == INT_MAX ? 0 : result;
    }
private:
    int binary_search(vector<int>& nums,int target, int lo, int hi) {
        while (hi-lo>1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target)
                hi = mid - 1;
            else if (nums[mid] <= target)
                lo = mid;           
        }
        if (nums[hi] <= target) return hi;
        if (nums[lo] <= target) return lo;
        return -1;
    }
};
int main() {
    Solution s; 
    vector<int> vec = { 2,3,1,2,4,3,100 };
    cout << s.minSubArrayLen2(7, vec) << endl;
    system("pause");
    return 0;
}