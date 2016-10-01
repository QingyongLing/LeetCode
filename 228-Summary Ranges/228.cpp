#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int index = 0,len=nums.size();
        while (index < len) {
            int temp = index + 1;
            while (temp < len&&nums[temp] == nums[temp - 1] + 1)
                ++temp;
            if (index == temp - 1)
                result.push_back(to_string(nums[index]));
            else
                result.push_back(to_string(nums[index]) + "->" + to_string(nums[temp - 1]));
            index = temp;
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 0,1,2,4,5,7 };
    auto result = s.summaryRanges(vec);
    for (auto &s : result)
        cout << s << " ";
    cout << endl;
    system("pause");
    return 0;
}