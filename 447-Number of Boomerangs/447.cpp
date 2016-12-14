#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) 
such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all 
in the range [-10000, 10000] (inclusive).
Example:
Input:
[[0,0],[1,0],[2,0]]
Output:
2
Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        auto size = points.size();
        int result = 0;
        unordered_map<int, int> map;
        for (size_t i = 0; i < size; ++i) {
            if (!map.empty()) map.clear();
            for (auto j = 0; j < size; ++j) {
                if (j == i) continue;
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                int distance = dx*dx + dy*dy;
                ++map[distance];
            }
            for (auto &p : map) {
                result += p.second*(p.second - 1);
            }
        }
        return result;
    }
};
int main() {
    cout <<  endl;
}