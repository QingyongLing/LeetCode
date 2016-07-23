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
                    temp += c*c*c*c;               
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
    // beats 99.92% of cppsubmissions  233333 
    vector<vector<string>> groupAnagrams4(vector<string>& strs) {
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
                    temp += c*c*c*c;              
                return temp;
            };
            vector<pair<size_t, string*>> data;
            for (auto &s : strs)
                data.push_back(make_pair(fun_hash(s), &s));
            sort(data.begin(), data.end(), [](pair<size_t, string*>& left, pair<size_t, string*>& right)
            {return left.first < right.first; });

            size_t temp = data[0].first;
            vector<string> tempstr;
            for (auto &p : data)
            {
                if (p.first != temp)
                {
                    temp = p.first;
                    result.push_back(tempstr);
                    tempstr.clear();
                    tempstr.push_back(*p.second);
                }
                else
                    tempstr.push_back(*p.second);
            }
            result.push_back(tempstr);
        }
        return result;
    }
    vector<vector<string>> groupAnagrams5(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }
        else
        {
            vector<string> sorted_strs = strs;
            for (auto &str : sorted_strs)
                sort(str.begin(), str.end());
            vector<pair<string*, string*>> data;
            for (int i = 0; i < strs.size(); ++i)
                data.push_back(make_pair(&sorted_strs[i], &strs[i]));
            sort(data.begin(), data.end(),[](pair<string*, string*> &left, pair<string*, string*> &right)->bool
            {return *left.first < *right.first; });
            vector<string> temp;
            for (int i = 0; i < data.size(); ++i)
            {
                if (i != 0 && *data[i].first != *data[i - 1].first)
                {
                    result.push_back(temp);
                    temp.clear();
                    temp.push_back(*data[i].second);
                }
                else
                {
                    temp.push_back(*data[i].second);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto result = s.groupAnagrams5(vec);
    for (auto &s : result)
    {
        for (auto &c : s)
            cout << c << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
