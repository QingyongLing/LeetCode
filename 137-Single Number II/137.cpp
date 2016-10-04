#include <iostream>
#include <vector>
using namespace std;
/*
Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0, threetimes = 0;
        for (auto &n : nums) {
            twice |= n&once;
            once ^= n;
            threetimes = once&twice;
            once &= ~threetimes;
            twice &= ~threetimes;
        }
        return once;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1 , 2, 1, 2, 4, 1, 2 };
    cout << s.singleNumber(vec) << endl;
    system("pause");
    return 0;
}