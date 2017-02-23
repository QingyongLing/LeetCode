#include <iostream>
#include <vector>
using namespace std;
/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater 
Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next
in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for
this number.
Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ascend, answer(nums.size()), stk;
        for (int i : nums) {
            if (ascend.empty())ascend.push_back(i);
            else if (i > ascend.back())ascend.push_back(i);
        }
        for (int i = nums.size() - 1; i > -1; --i) {
            while (!stk.empty() && !(nums[i] < stk.back()))
                stk.pop_back();
            if (stk.empty()) {
                auto iter = upper_bound(ascend.begin(), ascend.end(), nums[i]);
                answer[i] = iter == ascend.end() ? -1 : *iter;
            }
            else
                answer[i] = stk.back();
            stk.push_back(nums[i]);
        }
        return answer;
    }
};
int main() {
    Solution s;
    vector<int>  vec{ 1,2,3,4,5,6,5,4,5,1,2,3 };
    for (int i : s.nextGreaterElements(vec))
        cout << i << " ";
    cout << endl;
    return 0;
}
