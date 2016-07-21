#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/
class Solution {
public:
    void permutation(int n,vector<bool> &flag,vector<int> &temp, vector<int>& nums, vector<vector<int>> &result)
    {
        if (n == nums.size())
        {
            result.push_back(temp);
        }
        else
        {
            for (int i=0;i<nums.size();++i)
            {       
                if (!flag[i])
                {
                    if (i != 0 && nums[i] == nums[i - 1]&& flag[i-1])
                        continue;
                    temp.push_back(nums[i]);
                    flag[i] = true;
                    permutation(n + 1, flag, temp, nums, result);
                    temp.pop_back();
                    flag[i] = false;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 1)
        {
            result.push_back(nums);
            return result;
        }
        vector<bool> flag( nums.size(),false);
        sort(nums.begin(), nums.end());
        // auto temp=vector<int>();
        //permutation(0, flag, temp, nums, result);
        permutation(0,flag,vector<int>() ,nums, result);
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> vec = { 1,1,2,2 };
    auto result = s.permute(vec);
    for (auto &v : result)
    {
        for (auto &c : v)
            cout << c << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
