#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
Hint:
1.How many majority elements could it possibly have?
2.Do you have a better hint? Suggest it!
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int m = 0, n = 0, countm = 0, countn = 0;
        for (auto i : nums) {
            if (i == m)++countm;
            else if (i == n) ++countn;
            else if (countm == 0) m = i, countm = 1;
            else if (countn == 0) n == i, countn = 1;
            else --countm, --countn;
        }
        countm = 0, countn = 0;
        for (int i : nums) {
            if (i == m)++countm;
            if (i == n)++countn;
        }
        if (countm > nums.size() / 3)
            result.push_back(m);
        if (countn > nums.size() / 3)
            result.push_back(n);
        return result;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}