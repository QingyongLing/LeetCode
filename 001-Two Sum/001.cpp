
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution.
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
//UPDATE (2016/2/13):
// The return format had been changed to zero-based indices. Please read the above updated description carefully.

//author:  ling   time:2016.5.6

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <hash_map>
using namespace std;
class Solution
{
public:
    //beats 55.48% of C++   O(nlogn)
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int, int>> data;
        int index = 0;
        for_each(nums.cbegin(), nums.cend(), [&data, &index](const int& n)
        {
            data.push_back(make_pair(n, index++));
        });
        sort(data.begin(), data.end(), [](pair<int, int> a, pair<int, int> b)
        {
            return a.first < b.first;
        });
        for (int b = 0, e = data.size() - 1; e > b;)
        {
            if (data[b].first + data[e].first > target)
                --e;
            else if (data[b].first + data[e].first < target)
                ++b;
            else
            {
                if (data[b].second < data[e].second)
                    return { data[b].second, data[e].second };
                else
                    return { data[e].second, data[b].second };
            }
        }
        vector<int> indcies;
        return indcies;
    }
    //beats 23.79% of C++ O(nlogn)s
    vector<int> twoSum2(vector<int>& nums, int target)
    {
        map<int, int> data;
        int index = 0;
        for (auto c = nums.cbegin(); c != nums.cend(); ++c)
            data[*c] = index++;
        for (int b = 0, e = nums.size(); e > b; ++b)
        {
            int other = target - nums[b];
            if (data.find(other) != data.end() && b!=data[other])
            {
                return{ b, data[other] };
            }
        }
        vector<int> indcies;
        return indcies;
    }
    //beats 36.2% of C++  O(nlogn)
    vector<int> twoSum3(vector<int>& nums, int target)
    {
        map<int, int> data;
        for (int i = 0; i < nums.size(); ++i)
        {
            int other = target - nums[i];
            if (data.find(other) != data.end())
                return{ data[other], i };
            else
                data[nums[i]] = i;
        }
        vector<int> indcies;
        return indcies;
    }
    //leetcode do not support hash_map  O(n)
    vector<int> twoSum4(vector<int>& nums, int target)
    {
        hash_map<int, int> data;
        for (int i = 0; i < nums.size(); ++i)
        {
            int other = target - nums[i];
            if (data.find(other) != data.end())
                return{ data[other], i };
            else
                data[nums[i]] = i;
        }
        vector<int> indcies;
        return indcies;
    }
};
int main()
{
    vector<int> vec = { 3, 2, 11,34,67,88,44,33,5,33,45,4,867,898};
    Solution s;
    for (auto c : s.twoSum(vec, 6))
        cout << c << " ";
    for (auto c : s.twoSum4(vec, 6))
        cout << c << " ";
    return 0;
}
