#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such
that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || t<0 || k<0) return false;
        set<int> tree;
        for (int i = 0; i < nums.size(); ++i) {
            auto lower = tree.lower_bound(nums[i] - t);
            if (lower != tree.end() && abs(nums[i] - *lower) <= t)
                return true;
            tree.insert(nums[i]);
            if (tree.size() == k + 1)
                tree.erase(nums[i - k]);
        }
        return false;
    }
};
int main() {
    Solution s; 
    vector<int> vec = { 4,2 };
    cout << s.containsNearbyAlmostDuplicate(vec, 2, 1) << endl;
    system("pause");
    return 0;
}