#include <iostream>
#include <vector>
using namespace std;
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n >= k)
        {
            vector<int> vec;
            backtracking(vec, result, 1, n, k);
        }
        return result;
    }
    void backtracking(vector<int> &vec, vector<vector<int>> &result, int m, int n, int k)
    {
        if (k == 0)
            result.push_back(vec);
        else
        {
            for (int i = m; i <= n - k + 1; ++i)
            {
                vec.push_back(i);
                backtracking(vec, result, i + 1, n, k - 1);
                vec.pop_back();
            }
        }
    }
};
int main()
{  
    Solution s;
    auto vec = s.combine(4, 2);
    for (auto &c : vec)
    {
        for (auto &v : c)
            cout << v << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
