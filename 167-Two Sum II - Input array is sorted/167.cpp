#include <iostream>
#include <vector>
using namespace std;
/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        vector<int> result;
        while (lo<hi) {
            int temp = numbers[lo] + numbers[hi];
            if (temp == target) {
                result.push_back(lo + 1);
                result.push_back(hi + 1);
                break;
            }
            else if (temp > target)
                --hi;
            else
                ++lo;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> vec = { 2,7,11,15 };
    for (auto &v : s.twoSum(vec, 9))
        cout << v << endl;
    system("pause");
    return 0;
}