/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
Each number in C may only be used once in the combination. 
Note:
•All numbers (including target) will be positive integers.
•The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Author=Ling
Date=2016.6.5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //Runtime: 8 ms
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        if (target < 0||kinds_of==-1||target<candidates[0])
            return;
        if (target >= candidates[kinds_of])
        {
            num.push_back(candidates[kinds_of]);
            backtracking(result, candidates, num, target - candidates[kinds_of], kinds_of - 1);
            num.pop_back();
        }        
        while (kinds_of > 0 && candidates[kinds_of] == candidates[kinds_of - 1])
            --kinds_of;
        backtracking(result, candidates, num, target, kinds_of - 1);
    }
};
int main()
{
    Solution s;
    vector<int> v = { 10, 1, 1, 1, 2, 2, 7, 6, 1, 5 };
    auto result = s.combinationSum2(v, 8);
    for (auto &c : result)
    {
        for (auto &d : c)
            cout << d << " ";
        cout << endl;
    }
    return 0;
}