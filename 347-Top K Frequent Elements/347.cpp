#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
Note:
•You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
•Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
class Solution {
public:
    //nlogn
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int n : nums) ++map[n];
        vector<pair<int, int>> temp(map.begin(), map.end());
        sort(temp.begin(), temp.end(), [](pair<int, int> &a, pair<int, int> &b) {return a.second > b.second; });
        vector<int> result;
        for (int i = 0; i < k; ++i)
            result.push_back(temp[i].first);
        return result;
    }
    //beter than nlogn
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int n : nums) ++map[n];
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {return a.second > b.second; };
        vector<pair<int, int>> temp(map.begin(), map.end());
        vector<pair<int, int>> heapvec(temp.begin(), temp.begin() + k);
        make_heap(heapvec.begin(), heapvec.end(),cmp);
        for (auto i = temp.begin() + k; i != temp.end(); ++i) {
            heapvec.push_back(*i);
            push_heap(heapvec.begin(), heapvec.end(), cmp);
            pop_heap(heapvec.begin(), heapvec.end(), cmp);
            heapvec.pop_back();
        }
        vector<int> result;
        for (int i = 0; i < heapvec.size(); ++i)
            result.push_back(heapvec[i].first);
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 1,1,1,2,2,3 };
    auto result = s.topKFrequent2(vec, 2);
    for (auto i : result)
        cout << i << "  ";
    return 0;
}