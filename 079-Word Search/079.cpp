#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        row = board.size(), col = board[0].size();
        vector<vector<bool>> flag(row, vector<bool>(col, false));
        char l = *word.begin(), r = word.back();
        int leftnum = 0, rightnum = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == l)++leftnum;
                if (board[i][j] == r)++rightnum;
            }
        }
        if (rightnum > leftnum)
            reverse(word.begin(), word.end());
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (backtracking(board, flag, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool backtracking(vector<vector<char>>& board, vector<vector<bool>> &flag, int x, int y, string &word, int index)
    {
        if (board[x][y] == word[index])
        {
            if (index == word.size() - 1)
                return true;
            flag[x][y] = true;
            if (x - 1 >= 0 && !flag[x - 1][y] && backtracking(board, flag, x - 1, y, word, 1 + index))
                return true;
            if (y - 1 >= 0 && !flag[x][y - 1] && backtracking(board, flag, x, y - 1, word, 1 + index))
                return true;
            if (x + 1 < row && !flag[x + 1][y] && backtracking(board, flag, x + 1, y, word, 1 + index))
                return true;
            if (y + 1 < col && !flag[x][y + 1] && backtracking(board, flag, x, y + 1, word, 1 + index))
                return true;
            flag[x][y] = false;
        }
        return false;
    }
};
int main()
{  
    Solution s;
    vector<vector<char>> vec = {
        //{'A', 'B', 'C', 'E'},
        //{'S', 'F', 'C', 'S'},
        //{'A', 'D', 'E', 'E'}
        {'C','A','A'},
        {'A','A','A'},
        {'B','C','D'}
    };
    cout << (s.exist(vec, "AAB") ? "true" : "false") << endl;
    system("pause");
    return 0;
}
