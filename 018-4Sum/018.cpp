/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
•Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
•The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

author=Ling
date=2016.5.22
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    //Runtime: 68 ms
    //Your runtime beats 70.92% of cppsubmissions.
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int temp = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (target < temp)
                break;
            threesum(nums, i + 1, nums.size(), target - nums[i], nums[i], result);
        }
        return result;
    }
    void threesum(vector<int>& nums, int begin, int end,int target, int first, vector<vector<int>> &result)
    {
        int j = 0, k = 0, temp = 0;
        vector<int> ans(4, 0);
        for (int i = begin; i < end - 2; ++i)
        {
            temp = nums[i] + nums[i + 1] + nums[i + 2];
            if (target < temp)
                break;
            if (i > begin && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = end - 1;
            while (j < k)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    ++j; continue;
                }
                if (k + 1 < end - 1 && nums[k] == nums[k + 1])
                {
                    --k; continue;
                }
                temp = nums[i] + nums[j] + nums[k];
                if (temp < target)
                {
                    ++j; continue;
                }
                if (temp > target)
                {
                    --k; continue;
                }
                if (temp == target)
                {
                    ans[0] = first;
                    ans[1] = nums[i];
                    ans[2] = nums[j];
                    ans[3] = nums[k];
                    result.push_back(ans);
                    ++j;
                    --k;
                }
            }
        }
    }
    //Runtime: 84 ms
    //Your runtime beats 58.41% of cppsubmissions
    vector<vector<int>> fourSum2(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int temp = nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (target < temp)
                    break;
                twosum(nums, j + 1, nums.size() - 1, target - nums[i] - nums[j], nums[i], nums[j], result);
            }
        }
        return result;
    }
    void twosum(vector<int>& nums, int left, int right, int target, int first, int second, vector<vector<int>> &result)
    {
        vector<int> ans(4, 0);
        int j = left, k = right, temp=0;
        while (j < k)
        {
            if (j > left && nums[j] == nums[j - 1])
            {
                ++j; continue;
            }
            if (k < right - 1 && nums[k] == nums[k + 1])
            {
                --k; continue;
            }
            temp = nums[j] + nums[k];
            if (temp < target)
            {
                ++j; continue;
            }
            if (temp > target)
            {
                --k; continue;
            }
            if (temp == target)
            {
                ans[0] = first;
                ans[1] = second;
                ans[2] = nums[j];
                ans[3] = nums[k];
                result.push_back(ans);
                ++j;
                --k;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> vec = { 1, 0, -1, 0, -2, 2 };
    auto result = s.fourSum(vec, 0);
    for (auto &c : result)
    {
        for (auto &d : c)
            cout << d << "  ";
        cout << endl;
    }
    cout << endl;
}
