#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent,
the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right 
and bottom edges.
Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal 
or lower.
Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
Note:
1.The order of returned grid coordinates does not matter.
2.Both m and n are less than 150.
Example:
Given the following 5x5 matrix:
Pacific ~   ~   ~   ~   ~
~  1   2   2   3  (5) *
~  3   2   3  (4) (4) *
~  2   4  (5)  3   1  *
~ (6) (7)  1   4   5  *
~ (5)  1   1   2   4  *
*   *   *   *   * Atlantic
Return:
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if (matrix.empty()) return result;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        auto atlantic = pacific;
        deque<pair<int, int>> position;
        for (int i = 0; i < col; ++i)position.push_back(make_pair(0, i)), pacific[0][i] = true;
        for (int i = 1; i < row; ++i)position.push_back(make_pair(i, 0)), pacific[i][0] = true;
        bfs(matrix, position, pacific);
        position.clear();
        for (int i = 0; i < col; ++i)position.push_back(make_pair(row - 1, i)), atlantic[row - 1][i] = true;
        for (int i = 0; i < row - 1; ++i)position.push_back(make_pair(i, col - 1)), atlantic[i][col - 1] = true;
        bfs(matrix, position, atlantic);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back(make_pair(i, j));
            }
        }
        return result;
    }
    void bfs(vector<vector<int>>& matrix, deque<pair<int, int>>&pos, vector<vector<bool>> &flag) {
        int row = matrix.size(), col = matrix[0].size();
        int num = pos.size();
        int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
        while (num--) {
            pair<int, int> p = pos.front();
            pos.pop_front();
            for (int i = 0; i < 4; ++i) {
                int tempx = p.first + dx[i];
                int tempy = p.second + dy[i];
                if (tempx >= 0 && tempx < row&&tempy >= 0 && tempy < col) {
                    if (!flag[tempx][tempy] && matrix[tempx][tempy] >= matrix[p.first][p.second]) {
                        flag[tempx][tempy] = true;
                        pos.push_back(make_pair(tempx, tempy));
                    }
                }
            }
        }
        if (!pos.empty()) bfs(matrix, pos, flag);
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec = {
        { 1 , 2 , 2 , 3 , 5 },
        { 3 , 2 , 3 , 4 , 4 },
        { 2 , 4 , 5 , 3 , 1 },
        { 6 , 7 , 1 , 4 , 5 },
        { 5 , 1 , 1 , 2 , 4 }
    };
    auto result = s.pacificAtlantic(vec);
    for (auto &p : result)
        cout << p.first << "  " << p.second << endl;
    cout << endl;
}