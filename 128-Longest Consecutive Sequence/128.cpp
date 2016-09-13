#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> table;
        for (auto &n : nums)
            table.insert(n);
        int result = 0;
        for (auto &n : nums) {
            int curright = n, len = 0;
            while (1) {
                auto iter = table.find(++curright);
                if (iter != table.end())
                    table.erase(iter);
                else break;
            }
            int curleft = n;
            while (1) {
                auto iter = table.find(--curleft);
                if (iter != table.end())
                    table.erase(iter);
                else break;
            }
            result = max(result, curright - curleft - 1);
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> gas = { 0,3,7,2,5,8,4,6,0,1 };
    cout << s.longestConsecutive(gas) << endl;
    system("pause");
    return 0;
}