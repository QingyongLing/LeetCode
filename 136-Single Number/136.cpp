#include <iostream>
#include <vector>
using namespace std;
/*
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto &n : nums)
            result ^= n;
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1 , 2, 1, 2, 4 };
    cout << s.singleNumber(vec) << endl;
    system("pause");
    return 0;
}