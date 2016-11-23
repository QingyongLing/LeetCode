#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
•Each element in the result must be unique.
•The result can be in any order.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end()), set2(nums2.begin(), nums2.end());
        unordered_set<int> *lager = nullptr, *smaller = nullptr;
        if (set1.size() > set2.size())
            lager = &set1, smaller = &set2;
        else
            lager = &set2, smaller = &set1;
        vector<int> result;
        for (auto i : *smaller)
            if (lager->find(i)!=lager->end())
                result.push_back(i);
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec1{ 1,1,1,2,2,3 }, vec2{ 2,3 };
    for (auto i : s.intersection(vec1, vec2))
        cout << i << " ";    
    return 0;
}