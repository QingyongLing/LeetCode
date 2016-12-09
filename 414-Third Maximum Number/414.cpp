#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).
Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;
        vector<int> numbers;
        numbers.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            auto iter = find_if(numbers.begin(), numbers.end(), [&i, &nums](int a) { return a <= nums[i]; });
            if (iter != numbers.end() && *iter != nums[i])
                numbers.insert(iter, nums[i]);
            else if(iter == numbers.end())
                numbers.push_back(nums[i]);
            if (numbers.size() == 4)
                numbers.pop_back();
        }
        return numbers.size() == 3 ? numbers.back() : numbers.front();
    }
};

int main() {
    Solution s;
    vector<int> vec = { 3,2,2 };
    cout << s.thirdMax(vec)<< endl;
}