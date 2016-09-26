#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
Given an array of integers and an integer k, find out whether there are two distinct indices
i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size();++i) {
            auto iter = hashmap.find(nums[i]);
            if (iter != hashmap.end()) {
                if (i - iter->second <= k)
                    return true;
                else
                    iter->second = i;
            }
            else
                hashmap.insert(make_pair(nums[i], i));
        }
        return false;
    }
};
int main() {
    Solution s; 
    
    system("pause");
    return 0;
}