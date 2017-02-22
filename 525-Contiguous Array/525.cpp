#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> index;
        index.insert(make_pair(0, 0));
        int zero = 0, one = 0, answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] ? ++one : ++zero;
            int sub = one - zero;
            auto iter = index.find(sub);
            if (iter == index.end())
                index.insert(make_pair(sub, i + 1));
            else {
                answer = max(answer, i + 1 - iter->second);
            }
        }
        return answer;
    }
};
int main() {
    Solution s;
    return 0;
}
