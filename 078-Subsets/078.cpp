#include <iostream>
#include <vector>
using namespace std;
/*
Given a set of distinct integers, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int maxnum = 1 << size;
        vector<vector<int>> result;
        for (int i = 0; i < maxnum; ++i)
        {
            vector<int> vec;
            for (int j = 0; j < size; ++j)
            {
                if (1 & (i >> j))
                    vec.push_back(nums[j]);
            }
            result.push_back(vec);
        }
        return result;
    }
};
int main()
{  
    Solution s;
    vector<int> vec = { 1,2,3 };
    auto result = s.subsets(vec);
    for (auto &c : result)
    {
        for (auto &v : c)
            cout << v << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
