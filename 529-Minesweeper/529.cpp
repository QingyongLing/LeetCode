#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Let's play the minesweeper game (Wikipedia, online game)!
You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an
unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right,
and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, 
and finally 'X' represents a revealed mine.
Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return
the board after revealing this position according to the following rules:
1.If a mine ('M') is revealed, then the game is over - change it to 'X'.
2.If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of 
its adjacent unrevealed squares should be revealed recursively.
3.If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') 
representing the number of adjacent mines.
4.Return the board when no more squares will be revealed.
Example 1:
Input:
[['E', 'E', 'E', 'E', 'E'],
['E', 'E', 'M', 'E', 'E'],
['E', 'E', 'E', 'E', 'E'],
['E', 'E', 'E', 'E', 'E']]
Click : [3,0]
Output:
[['B', '1', 'E', '1', 'B'],
['B', '1', 'M', '1', 'B'],
['B', '1', '1', '1', 'B'],
['B', 'B', 'B', 'B', 'B']]
Explanation:
Example 2:
Input:
[['B', '1', 'E', '1', 'B'],
['B', '1', 'M', '1', 'B'],
['B', '1', '1', '1', 'B'],
['B', 'B', 'B', 'B', 'B']]
Click : [1,2]
Output:
[['B', '1', 'E', '1', 'B'],
['B', '1', 'X', '1', 'B'],
['B', '1', '1', '1', 'B'],
['B', 'B', 'B', 'B', 'B']]
Explanation:
Note:
1.The range of the input matrix's height and width is [1,50].
2.The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at 
least one clickable square.
3.The input board won't be a stage when game is over (some mines have been revealed).
4.For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all 
the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
*/

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty())return board;
        row = board.size();
        col = board[0].size();
        int cx = click[0], cy = click[1];
        if (!inplan(cx, cy))return board;
        if (board[cx][cy] == 'M') {
            board[cx][cy] = 'X';
            return board;
        }
        if (board[cx][cy] == 'E') {
            clickemptysquare(board, cx, cy);
        }
        return board;
    }
private:
    int row, col;
    const int dx[8] = { -1,-1,-1,0,1,1,1,0 };
    const int dy[8] = { -1,0,1,1,1,0,-1,-1 };
    void clickemptysquare(vector<vector<char>>& board, int x, int y) {
        int num = minenumber(board, x, y);
        if (num) {
            board[x][y] = num + '0';
        }
        else {
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tempx = x + dx[i], tempy = y + dy[i];
                if (inplan(tempx, tempy) && board[tempx][tempy] == 'E')
                    clickemptysquare(board, tempx, tempy);
            }
        }
    }
    int minenumber(vector<vector<char>>& board, int x, int y) {
        int num = 0;
        for (int i = 0; i < 8; ++i) {
            int tempx = x + dx[i], tempy = y + dy[i];
            if (inplan(tempx, tempy) && board[tempx][tempy] == 'M')
                ++num;
        }
        return num;
    }
    bool inplan(int x, int y) {
        if (x > -1 && x<row&&y>-1 && y < col)
            return true;
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> vec{
        { 'E','E','E','E','E' },
        { 'E','E','M','E','E' },
        { 'E','E','E','E','E' },
        { 'E','E','E','E','E' } };
    vector<int> click = { 3,0 };
    auto b = s.updateBoard(vec, click);
    for (vector<char>& v : b) {
        for (auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
}
