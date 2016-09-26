#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]
Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 1) return{ {n} };
        vector<vector<int>> result;
        vector<int> vec;
        backtracking(result, vec, k, n, 9);
        return result;
    }
private:
    void backtracking(vector<vector<int>> &result,vector<int> &temp,int k,int n,int cur) {
        if (k == 0 && n == 0)
            result.push_back(temp);
        if (k <= 0 || cur <= 0 || n <= 0)
            return;      
        temp.push_back(cur);
        backtracking(result, temp, k - 1, n - cur, cur - 1);
        temp.pop_back();
        backtracking(result, temp, k, n, cur - 1);
    }
};
int main() {
    Solution s; 
    auto result = s.combinationSum3(2, 9);
    for (auto &v : result) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}