#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <set>
#include <functional>
using namespace std;
/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver
Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
1.N is a positive integer and won't exceed 10,000.
2.All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> pairnums;
        for (int i = 0; i < nums.size(); ++i) {
            pairnums.push_back(make_pair(nums[i], i));
        }
        sort(pairnums.begin(), pairnums.end(), greater<pair<int,int>>());
        vector<string> result(nums.size());
        for (int i = 0; i < pairnums.size(); ++i) {
            if (i < 3) {
                string strs[] = { "Gold Medal", "Silver Medal", "Bronze Medal" };
                result[pairnums[i].second] = strs[i];
            }
            else {
                result[pairnums[i].second] = to_string(i + 1);
            }
        }
        return result;
    }
};

int main() {
    //不测试了=_=
    return 0;
}