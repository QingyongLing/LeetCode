/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.

Author=Ling
Date=2016.6.4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //Runtime: 8 ms
    void solveSudoku(vector<vector<char>>& board) {
        bool rowflag[9][10] = { {false} };
        bool colflag[9][10] = { {false} };
        bool box[9][10] = { {false} };
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    rowflag[i][board[i][j] - '0'] = true;
                    colflag[j][board[i][j] - '0'] = true;
                    box[(i / 3) * 3 + j / 3][board[i][j] - '0'] = true;
                }
            }
        }
        bool solved = false;
        backtracking(solved, board, 0, 0, rowflag, colflag, box);
    }
    void backtracking(bool& solved, vector<vector<char>>& board, int i, int j, bool(*rowflag)[10], bool(*colflag)[10], bool(*box)[10])
    {
        if (i == board.size() - 1 && j == board[0].size())
        {
            solved = true;
            return;
        }
        if (j == board[0].size())
        {
            ++i;
            j = 0;
        }
        if (board[i][j] != '.')
            backtracking(solved,board, i, j + 1, rowflag, colflag, box);
        else
        {
            for (int n = 1; n <= 9; ++n)
            {
                if (!rowflag[i][n] && !colflag[j][n] && !box[(i / 3) * 3 + j / 3][n])
                {
                    board[i][j] = n + '0';
                    rowflag[i][n] = colflag[j][n] = box[(i / 3) * 3 + j / 3][n] = true;
                    backtracking(solved,board, i, j + 1, rowflag, colflag, box);
                    if (solved) return;
                    rowflag[i][n] = colflag[j][n] = box[(i / 3) * 3 + j / 3][n] = false;
                    board[i][j] = '.';
                }
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<char>> v;
    for (int i = 0; i < 9;++i)
        v.push_back(vector<char>(9, '.'));
    s.solveSudoku(v);
    for (auto &c : v)
    {
        for (auto &d : c)
            cout << d << " ";
        cout << endl;
    }
    return 0;
}
