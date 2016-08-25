#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.empty())
            return result;
        string divide;
        backtracking(result, divide, s, 0, 0);
        return result;
    }
    void backtracking(vector<string> &result,string &divide,string &s, int num, int index) {
        if (num == 4 && index == s.size())
            result.push_back(divide);
        else if (num > 4 || index >= s.size())
            return;
        else {
            int appendnum = 0;
            for (int i = 0; i < 3; ++i){
                if (index + i < s.size() && valid(s, index, index + i)) {
                    divide.push_back(s[index + i]);
                    ++appendnum;
                    if (num < 3)
                        divide.push_back('.');
                    backtracking(result, divide, s, num + 1, index + i + 1);
                    if (num < 3)
                        divide.pop_back();
                }
            }
            divide.erase(divide.end() - appendnum, divide.end());
        }
    }
    bool valid(string& s, int left, int right) {
        if (left == right)
            return true;
        else if (left == right - 1 && s[left] > '0')
            return true;
        else {
            if (s[left] == '1')
                return true;
            else if (s[left] == '2'){
                int num = 200;
                num += (s[left + 1] - '0') * 10;
                num += s[left + 2] - '0';
                if (num <= 255)
                    return true;
            }
        }
        return false;
    }
};
int main()
{  
    Solution s;
    string str = "120345";
    auto result = s.restoreIpAddresses(str);
    for (auto &s : result)
    {
        cout << s << endl;
    }
    system("pause");
    return 0;
}
