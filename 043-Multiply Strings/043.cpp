/*
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note:
•The numbers can be arbitrarily large and are non-negative.
•Converting the input string to integer is NOT allowed.
•You should NOT use internal library such as BigInteger.

Author=Ling
Date=2016.6.8
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
     string multiply(string num1, string num2)
     {
        string result = { "0" };
        if (num1 == result || num2 == result)
            return result;
        string &smaller = num1.size() < num2.size() ? num1 : num2;
        string &bigger = num1.size() < num2.size() ? num2 : num1;
        map<char, string> multmap;
        string tempstr;
        for (int i = 0; i < smaller.size(); ++i)
        {
            if (smaller[smaller.size() - i - 1] == '0') continue;
            auto iter = multmap.find(smaller[smaller.size() - i - 1]);
            if (iter == multmap.end())
            {
                multiplywithachar(tempstr, bigger, smaller[smaller.size() - i - 1]);
                multmap[smaller[smaller.size() - i - 1]] = tempstr;
                addtwostr(result, tempstr, i);
            }
            else
                addtwostr(result, iter->second, i);
        }
        reverse(result.begin(),result.end());
        return result;
    }
    void multiplywithachar(string& result, string& longstr, char shortstr)
    {
        if (!result.empty())
            result.clear();
        result.push_back('0');
        int num, unit, decade;
        for (int i = longstr.size() - 1; i >= 0; --i)
        {
            num = (longstr[i] - '0') * (shortstr - '0');
            decade = num / 10;
            unit = num % 10 + (result.back() - '0');
            if (unit > 9)
            {
                unit = unit - 10;
                decade++;
            }
            result.back() = static_cast<char>(unit + '0');
            result.push_back(static_cast<char>(decade + '0'));
        }
        if (result.back() == '0')
            result.pop_back();
    }
    void addtwostr(string& result, string& addstr, int index)
    {
        auto num = addstr.size() + index - result.size();
        if (num != 0) result.append(string(num, '0'));
        auto result_iter = result.begin(), addstr_iter = addstr.begin();
        while (index-- != 0) ++result_iter;
        int sumoftwo = 0, decade = 0;
        //&& addstr_iter != addstr.end()
        for (; result_iter != result.end() ; ++result_iter, ++addstr_iter)
        {
            sumoftwo = (*result_iter - '0') + (*addstr_iter - '0') + decade;
            *result_iter = static_cast<char>(sumoftwo % 10 + '0');
            decade = sumoftwo / 10;
        }
        if (decade != 0)
            result.push_back(static_cast<char>(decade + '0'));
    }
    //slower about 32/28ms
    string multiply2(string num1, string num2) {
        static vector<vector<string>> multdata = {
                { "0", "0", "0", "0", "0", "0", "0", "0", "0", "0" },
                { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" },
                { "0", "2", "4", "6", "8", "10", "12", "14", "16", "18" },
                { "0", "3", "6", "9", "12", "15", "18", "21", "24", "27" },
                { "0", "4", "8", "12", "16", "20", "24", "28", "32", "36" },
                { "0", "5", "10", "15", "20", "25", "30", "35", "40", "45" },
                { "0", "6", "12", "18", "24", "30", "36", "42", "48", "54" },
                { "0", "7", "14", "21", "28", "35", "42", "49", "56", "63" },
                { "0", "8", "16", "24", "32", "40", "48", "56", "64", "72" },
                { "0", "9", "18", "27", "36", "45", "54", "63", "72", "81" } };
        static vector<vector<string>> adddata = {
                { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" },
                { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" },
                { "2", "3", "4", "5", "6", "7", "8", "9", "10", "11" },
                { "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" },
                { "4", "5", "6", "7", "8", "9", "10", "11", "12", "13" },
                { "5", "6", "7", "8", "9", "10", "11", "12", "13", "14" },
                { "6", "7", "8", "9", "10", "11", "12", "13", "14", "15" },
                { "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" },
                { "8", "9", "10", "11", "12", "13", "14", "15", "16", "17" },
                { "9", "10", "11", "12", "13", "14", "15", "16", "17", "18" } };
        string result = { "0" };
        if (num1 == result || num2 == result)
            return result;
        string &smaller = num1.size() < num2.size() ? num1 : num2;
        string &bigger = num1.size() < num2.size() ? num2 : num1;
        map<char, string> multmap;
        string tempstr;
        for (int i = 0; i < smaller.size(); ++i)
        {
            if (smaller[smaller.size() - i - 1] == '0') continue;
            auto iter = multmap.find(smaller[smaller.size() - i - 1]);
            if (iter == multmap.end())
            {
                multiplywithachar2(tempstr, bigger, smaller[smaller.size() - i - 1], multdata, adddata);
                multmap[smaller[smaller.size() - i - 1]] = tempstr;
                addtwostr2(result, tempstr, i, adddata);
            }
            else
                addtwostr2(result, iter->second, i, adddata);
        }
        return string(result.rbegin(), result.rend());
    }
    void multiplywithachar2(string& result, string& longstr, char shortstr,
        vector<vector<string>>& multdata, vector<vector<string>> &adddata)
    {
        if (!result.empty())
            result.clear();
        result.push_back('0');
        for (int i = longstr.size() - 1; i >= 0; --i)
        {
            string &temp1 = multdata[shortstr - '0'][longstr[i] - '0'];
            if (temp1.size() == 1)
            {
                string &temp2 = adddata[temp1[0] - '0'][result.back() - '0'];
                result.back() = temp2.back();
                if (temp2.size() == 1)
                    result.push_back('0');
                else
                    result.push_back(temp2[0]);
            }
            else
            {
                string &temp2 = adddata[temp1[1] - '0'][result.back() - '0'];
                result.back() = temp2.back();
                if (temp2.size() == 1)
                    result.push_back(temp1[0]);
                else
                    result.push_back(adddata[temp2[0] - '0'][temp1[0] - '0'][0]);
            }
        }
        if (result.back() == '0')
            result.pop_back();
    }
    void addtwostr2(string& result, string& addstr,int index, vector<vector<string>> &adddata)
    {
        auto num = addstr.size() + index - result.size();
        if (num != 0) result.append(string(num, '0'));
        auto result_iter = result.begin(), addstr_iter = addstr.begin();
        while (index-- != 0) ++result_iter;
        char add = '0';
        for (; result_iter != result.end() && addstr_iter != addstr.end(); ++result_iter, ++addstr_iter)
        {
            string &temp = adddata[*result_iter - '0'][*addstr_iter - '0'];
            if (temp.size() == 1)
            {
                string &temp2 = adddata[add - '0'][temp[0] - '0'];
                *result_iter = temp2.size() == 1 ? temp2[0] : temp2[1];
                add = temp2.size() == 1 ? '0' : temp2[0];
            }
            else
            {
                *result_iter = adddata[add - '0'][temp[1] - '0'][0];
                add = temp[0];
            }
        }
        if (add != '0')
            result.push_back(add);
    }
};

int main()
{
    Solution s;
    cout<<s.multiply("1234567890", "9876543210")<<endl;
    cout<<s.multiply2("1234567890", "9876543210")<<endl;
    return 0;
}
