#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
using namespace std;
/*
The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
For example,
There exist two distinct solutions to the 4-queens puzzle:
[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]

*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n == 0 || n == 2)
            return result;
        string str(n, '.');
        vector<string> position(n, str);
        vector<int> QueensCol;
        placeQueens(result, position, QueensCol, 0, n);
        return result;
    }
    void placeQueens(vector<vector<string>>& result, vector<string>& position, vector<int> &QueensCol, int row, int n)
    {
        if (row == n)
            result.push_back(position);
        for (int i = 0; i < n; ++i)
        {
            bool Noconflict = true;
            for (int j = 0; j < QueensCol.size(); ++j)
                if (i == QueensCol[j] || row - j == abs(i - QueensCol[j]))
                {
                    Noconflict = false;
                    break;
                }
            if (Noconflict)
            {
                position[row][i] = 'Q';
                QueensCol.push_back(i);
                placeQueens(result, position, QueensCol, row + 1, n);
                position[row][i] = '.';
                QueensCol.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens2(int n) {       
        if (n == 0)
            return vector<vector<string>>();         
        vector<int> QueensCol;
        vector<vector<int>> QueensCols;
        placeQueens2(QueensCols,QueensCol, 0, n);
        string str(n, '.');
        vector<string> position(n, str);
        vector<vector<string>> result(QueensCols.size(), position);
        for (int i = 0; i < QueensCols.size(); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result[i][j][QueensCols[i][j]] = 'Q';
            }
        }
        return result;
    }
    void placeQueens2(vector<vector<int>>& QueensCols, vector<int> &QueensCol,int row,int n)
    {
        if (row == n)
            QueensCols.push_back(QueensCol);
        for (int i = 0; i < n; ++i)
        {           
            bool Noconflict = true;
            for (int j = 0; j < QueensCol.size(); ++j)
            {
                if (i == QueensCol[j] || row - j == abs(i - QueensCol[j]))
                {
                    Noconflict = false;
                    break;
                }
            }
            if (Noconflict)
            {               
                QueensCol.push_back(i);
                placeQueens2(QueensCols, QueensCol , row + 1, n);
                QueensCol.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens3(int n) {
        vector<vector<string>> result;
        if (n == 0)
            return result;
        string str(n, '.');
        vector<string> position(n, str);
        placeQueens3(result, position, 0, n);
        return result;
    }
    void placeQueens3(vector<vector<string>>& result, vector<string>& position, int row, int n)
    {
        if (row == n)
            result.push_back(position);
        for (int i = 0; i < n; ++i)
        {
            if (Noconflict3(position, row, i, n))
            {
                position[row][i] = 'Q';
                placeQueens3(result, position, row + 1, n);
                position[row][i] = '.';
            }
        }
    }
    bool Noconflict3(const vector<string>& position, int x, int y, int n)
    {
        for (int k = 0; k < x; ++k)
        {
            if (position[k][y] == 'Q')
                return false;
        }
        int tempx = x, tempy = y;
        while (tempx > 0 && tempy > 0)
        {
            --tempx;
            --tempy;
            if (position[tempx][tempy] == 'Q')
                return false;
        }
        tempx = x, tempy = y;
        while (tempx > 0 && tempy < n - 1)
        {
            --tempx;
            ++tempy;
            if (position[tempx][tempy] == 'Q')
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    auto result = s.solveNQueens(4);
    for (auto &NQueens : result)
    {
        for (auto &str : NQueens)
            cout << str << endl;
        cout << "-------------------------" << endl;
    }
    system("pause");
    return 0;
}
