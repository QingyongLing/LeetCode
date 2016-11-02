#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
Example 1:
nums = [
[9,9,4],
[6,6,8],
[2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].
Example 2:
nums = [
[3,4,5],
[3,2,6],
[2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> flag(row, vector<int>(col, INT_MAX));
        int result = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                flag[i][j] = dfs(matrix, flag, i, j);
                result = max(result, flag[i][j]);
            }
        }
        return result;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &flag,int x,int y) {
        if (flag[x][y] != INT_MAX)
            return flag[x][y];
        else
            flag[x][y] = 1;
        int row = matrix.size(), col = matrix[0].size();
        int dx[] = { -1,0,1,0 };
        int dy[] = { 0,1,0,-1 };
        for (int i = 0; i < 4; ++i) {
            if (x + dx[i] >= 0 && x + dx[i] < row&&y + dy[i] >= 0 && y + dy[i] < col
                &&matrix[x + dx[i]][y + dy[i]] < matrix[x][y]) {
                flag[x][y] = max(flag[x][y], dfs(matrix, flag, x + dx[i], y + dy[i]) + 1);
            }
        }
        return flag[x][y];
    }
};
int main() {
    Solution s;
    vector<vector<int>> vec = { {9,9,4},{6,6,8},{2,1,1} };
    cout << s.longestIncreasingPath(vec) << endl;
    return 0;
}