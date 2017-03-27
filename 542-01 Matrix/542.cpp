#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Example 1:
Input:
0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:
0 0 0
0 1 0
1 1 1
Output: 
0 0 0
0 1 0
1 2 1
Note:
1.The number of elements of the given matrix will not exceed 10,000.
2.There are at least one 0 in the given matrix.
3.The cells are adjacent in only four directions: up, down, left and right.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())return vector<vector<int>>();
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> update(row, vector<int>(col, INT_MAX));
        set<pair<int, int>> data;
        for (int i = 0; i<row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    update[i][j] = 0;
                    data.insert(make_pair(i, j));
                }
            }
        }
        findzero(matrix, update, data);
        return update;
    }
    void findzero(vector<vector<int>>& matrix, vector<vector<int>>& update, set<pair<int, int>> &data) {
        static int dx[] = { -1,0,1,0 };
        static int dy[] = { 0,1,0,-1 };
        int row = matrix.size(), col = matrix[0].size();
        int num = data.size();
        set<pair<int, int>> newdata;
        for (auto iter = data.begin(); iter != data.end(); ++iter) {
            int x = iter->first, y = iter->second;
            for (int i = 0; i < 4; ++i) {
                int tempx = dx[i] + x;
                int tempy = dy[i] + y;
                if (tempx > -1 && tempx<row&&tempy>-1 && tempy < col) {
                    if (update[tempx][tempy] == INT_MAX)
                        newdata.insert(make_pair(tempx, tempy));
                    update[tempx][tempy] = min(update[tempx][tempy], update[x][y] + 1);
                }
            }
        }
        if (!newdata.empty())
            findzero(matrix, update, newdata);
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec = { { 0,0,0 },{ 0,1,0 },{ 1,1,1 } };
    auto v = s.updateMatrix(vec);
    for (auto c : v) {
        for (auto i : c)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}