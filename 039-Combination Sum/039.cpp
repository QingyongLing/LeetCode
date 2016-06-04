/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
•All numbers (including target) will be positive integers.
•The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
 A solution set is:
[
  [7],
  [2, 2, 3]
]

Author=Ling
Date=2016.6.4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.size() == 0)
            return result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtracking(result, candidates, temp, target, candidates.size() - 1);
        return result;
    }
    void backtracking(vector<vector<int>>& result, vector<int>&  candidates,vector<int> &num, int target, int kinds_of)
    {
        if (target == 0)
        {
            result.push_back(num);
            return;
        }
        if (target < 0||kinds_of==-1)
            return;
        backtracking(result, candidates, num, target, kinds_of - 1);
        if(target>=candidates[kinds_of])
        {
            num.push_back(candidates[kinds_of]);
            backtracking(result, candidates, num, target - candidates[kinds_of], kinds_of);
            num.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<int> v = { 2, 3, 4, 7 };
    auto result = s.combinationSum(v, 7);
    for (auto &c : result)
    {
        for (auto &d : c)
            cout << d << " ";
        cout << endl;
    }
    return 0;
}
