#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
Note:
•Each element in the result should appear as many times as it shows in both arrays.
•The result can be in any order.
Follow up:
•What if the given array is already sorted? How would you optimize your algorithm?
•What if nums1's size is small compared to nums2's size? Which algorithm is better?
•What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1, map2;
        for (auto i : nums1) ++map1[i];
        for (auto i : nums2) ++map2[i];
        unordered_map<int,int> *lager = nullptr, *smaller = nullptr;
        if (map1.size() > map2.size())
            lager = &map1, smaller = &map2;
        else
            lager = &map1, smaller = &map2;
        vector<int> result;
        for (auto &i : *smaller) {
            auto iter = lager->find(i.first);
            if (iter != lager->end()) {
                int num = min(i.second, iter->second);
                for (int j = 0; j < num; ++j)
                    result.push_back(i.first);
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec1{ 1,1,1,2,2,3 }, vec2{ 2,2,3 };
    for (auto i : s.intersection(vec1, vec2))
        cout << i << " ";    
    return 0;
}