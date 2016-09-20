#include <algorithm>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1
Example 2:
11000
11000
00100
00011
Answer: 3
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size(), result = 0;
        vector<vector<bool>> flag(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!flag[i][j] && grid[i][j] == '1') {
                    bfs(flag, grid, i, j);
                    ++result;
                }
            }
        }
        return result;
    }
private:
    void bfs(vector<vector<bool>> &flag, vector<vector<char>>& grid,int x,int y) {
        int row = grid.size(), col = grid[0].size();
        deque<pair<int, int>> elems;
        flag[x][y] = true;
        elems.push_back(make_pair(x, y));
        int dx[] = { 0,1,0,-1 };
        int dy[] = { 1,0,-1,0 };
        while (!elems.empty()) {
            int num = elems.size();
            while (num--) {
                pair<int, int> cur = elems.front();
                elems.pop_front();
                for (int i = 0; i < 4; ++i) {
                    int m = cur.first + dx[i], n = cur.second + dy[i];
                    if (m >= 0 && m < row&&n >= 0 && n < col) {
                        if (!flag[m][n] && grid[m][n] == '1') {
                            flag[m][n] = true;
                            elems.push_back(make_pair(m, n));
                        }
                    }
                }
            }
        }
    }
};
int main() {
    Solution s;  
    system("pause");
    return 0;
}