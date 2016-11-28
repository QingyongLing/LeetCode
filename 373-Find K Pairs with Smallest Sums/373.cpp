#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
Return: [1,2],[1,4],[1,6]
The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
Return: [1,1],[1,1]
The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3
Return: [1,3],[2,3]
All possible pairs are returned from the sequence:
[1,3],[2,3]
Credits:
Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.
*/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> heapvec, result;
        if (nums1.empty() || nums2.empty()) return result;
        for (int i : nums1) heapvec.push_back(make_pair(i, 0));
        auto cmp = [&nums2](pair<int, int> &a, pair<int, int> &b) {
            return a.first + nums2[a.second] > b.first + nums2[b.second];
        };
        make_heap(heapvec.begin(), heapvec.end(), cmp);
        while (!heapvec.empty() && result.size() < k) {
            pair<int, int> &p = heapvec.front();
            result.push_back(make_pair(p.first, nums2[p.second]));
            pop_heap(heapvec.begin(), heapvec.end(), cmp);
            if (++heapvec.back().second == nums2.size())
                heapvec.pop_back();
            else
                push_heap(heapvec.begin(), heapvec.end(), cmp);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> vec1 = { 1,7,11 }, vec2 = { 2,4,6 };
    auto result = s.kSmallestPairs(vec1, vec2, 3);
    for (auto &p : result)
        cout << "[" << p.first << ", " << p.second << "] ";
    return 0;
}