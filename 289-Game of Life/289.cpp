#include <iostream>
#include <vector>
using namespace std;
/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2.Any live cell with two or three live neighbors lives on to the next generation.
3.Any live cell with more than three live neighbors dies, as if by over-population..
4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.
Follow up:
1.Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
2.In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                board[i][j] = getneighbornum(board, i, j);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] > 0 && board[i][j] < 2)
                    board[i][j] = 0;
                else if (board[i][j] == 2 || board[i][j] == 3)
                    board[i][j] = 1;
                else if (board[i][j] > 3)
                    board[i][j] = 0;
                else if (board[i][j] == -3)
                    board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
private:
    int getneighbornum(vector<vector<int>>& board, int x, int y) {
        int dx[] = { -1,0,1,1,1,0,-1,-1 };
        int dy[] = { 1,1,1,0,-1,-1,-1,0 };
        int count = 0, row = board.size(), col = board[0].size();
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < row&&ny >= 0 && ny < col&&board[nx][ny] >0)
                ++count;
        }
        if (board[x][y] == 1) {
            return count == 0 ? INT_MAX : count;
        }
        else return -count;
    }
};
int main() {    
    vector<vector<int>> vec = { {1,0,0,0,0,1},{0,0,0,1,1,0},{1,0,1,0,1,0},
    {1,0,0,0,1,0},{1,1,1,1,0,1},{0,1,1,0,1,0},
    {1,0,1,0,1,1},{1,0,0,1,1,1},{1,1,0,0,0,0} };
    Solution s;
    s.gameOfLife(vec);
    for (auto &v : vec) {
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}