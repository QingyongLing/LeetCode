/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules(http://sudoku.com.au/TheRules.aspx).
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.
Note:
 A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 

Author=Ling
Date=2016.6.3
*/
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9)
            return false;
        bool box[9][10] = { false };
        for (int i = 0; i < board.size(); ++i)
        {
            bool flag[10] = { false };
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    if (flag[board[i][j] - '0'])
                        return false;
                    else
                        flag[board[i][j] - '0'] = true;
                    if (box[(i / 3) * 3 + j / 3][board[i][j] - '0'])
                        return false;
                    else
                        box[(i / 3) * 3 + j / 3][board[i][j] - '0'] = true;
                }
            }
        }       
        for (int i = 0; i < board[0].size(); ++i)
        {
            bool flag[10] = { false };
            for (int j = 0; j < board.size(); ++j)
            {
                if (board[j][i] != '.')
                {
                    if (flag[board[j][i] - '0'])
                        return false;
                    else
                        flag[board[j][i] - '0'] = true;                
                }
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}