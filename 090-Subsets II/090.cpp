#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty())
            return{ {} };
        sort(nums.begin(), nums.end());
        vector<int> sub;
        backtracking(result, nums, sub, 0);
        return result;
    }
    void backtracking(vector<vector<int>> &result, vector<int>& nums, vector<int>& sub,int n){
        if (n == nums.size())
            result.push_back(sub);
        else {            
             if (sub.empty() || !sub.empty() && sub.back() != nums[n])
                 backtracking(result, nums, sub, n + 1);
             sub.push_back(nums[n]);
             backtracking(result, nums, sub, n + 1);
             sub.pop_back();            
        }
    }
};
int main()
{  
    Solution s;
    vector<int> vec = { 1,2,2 };
    auto result = s.subsetsWithDup(vec);
    for (auto &c : result)
    {
        for (auto &v : c)
            cout << v << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
