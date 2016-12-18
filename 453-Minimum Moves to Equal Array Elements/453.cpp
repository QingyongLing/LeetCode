#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
Example:
Input:
[1,2,3]
Output:
3
Explanation:
Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) return 0;
        int minnum = nums[0];
        for (int i : nums) minnum = min(minnum, i);
        int result = 0;
        for (int i : nums) result += i - minnum;
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 1,2,3 };
    cout << s.minMoves(vec) << endl;
}