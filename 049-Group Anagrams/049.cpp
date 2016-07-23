#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
using namespace std;
/*
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note: All inputs will be in lower-case.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }
        else
        {
            auto old = strs;
            for (auto &s : strs)
                sort(s.begin(), s.end());
            map<size_t, vector<int>> m;
            std::hash<std::string> hash_fn;
            for (int i = 0; i < strs.size(); ++i)
            {
                m[hash_fn(strs[i])].push_back(i);
            }
            for (auto &s : m)
            {
                vector<string> temp;
                for (auto &c : s.second)
                    temp.push_back(old[c]);
                result.push_back(temp);
            }
        }
        return result;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }
        else
        {
            auto fun_hash = [](const string& str)->string
            {
                int num[26] = {};
                for (auto &c : str)
                    ++num[c - 'a'];
                string temp;
                for (int i = 0; i < 26; ++i)
                {
                    if (num[i] != 0)
                    {
                        temp.push_back(static_cast<char>(num[i]));
                        temp.append(",");
                    }
                    else
                        temp.append(",");
                }
                return temp;
            };
            map<size_t, vector<int>> m;
            std::hash<std::string> hash_fn;
            for (int i = 0; i < strs.size(); ++i)
            {
                m[hash_fn(fun_hash(strs[i]))].push_back(i);
            }
            for (auto &s : m)
            {
                vector<string> temp;
                for (auto &c : s.second)
                    temp.push_back(strs[c]);
                result.push_back(temp);
            }
        }
        return result;
    }
    //一个狗血的方法
    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }
        else
        {
            auto fun_hash = [](const string& str)->size_t
            {
                size_t temp = 0;
                for (auto &c : str)
                {
                    temp += c*c*c*c;
                }
                return temp;
            };
            map<size_t, vector<int>> m;
            for (int i = 0; i < strs.size(); ++i)
            {
                m[fun_hash(strs[i])].push_back(i);
            }
            for (auto &s : m)
            {
                vector<string> temp;
                for (auto &c : s.second)
                    temp.push_back(strs[c]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto result = s.groupAnagrams2(vec);
    for (auto &s : result)
    {
        for (auto &c : s)
            cout << c << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
