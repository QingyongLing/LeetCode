#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
/*
Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
bool compare(string &str1, string &str2) {
    int num = max(str1.size(), str2.size());
    int i = 0, j = 0;
    while (i<num&&j<num) {
        if (i == str1.size())
            i = 0;
        if (j == str2.size())
            j = 0;
        if (str1[i] > str2[j])
            return true;
        if (str1[i] < str2[j])
            return false;
        ++i;
        ++j;
    }
    if (str1.size() == str2.size())
        return false;
    else
        return str1 + str2 > str2 + str1;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        vector<string> strs;
        for (auto &n : nums) {
            strs.push_back(to_string(n));
        }
        sort(strs.begin(), strs.end(), compare);
        for (auto &s : strs)
            result += s;
        size_t index = result.find_first_not_of('0');
        if (index == 0)
            return result;
        else if (index == string::npos)
            return string("0");
        else
            return string(result.begin() + index, result.end());
    }   
};
int main() {
    Solution s;
    vector<int> vec = { 3, 30, 34, 5, 9 };
    cout << s.largestNumber(vec) << endl;    
    system("pause");
    return 0;
}