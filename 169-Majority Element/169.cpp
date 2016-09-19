#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxcount = 0, maxnum = 0;
        unordered_map<int, int> map;
        for (auto &n : nums) {
            int temp = ++map[n];
            if (temp>maxcount) {
                maxcount = temp;
                maxnum = n;
            }
        }
        return maxnum;
    }
    int majorityElement2(vector<int>& nums) {
        int result = 0, count = 0;
        for (auto &n : nums) {
            if (count == 0) {
                ++count;
                result = n;
            }else{
                if (n == result)
                    ++count;
                else
                    --count;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    
    system("pause");
    return 0;
}