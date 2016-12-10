#include <iostream>
#include <vector>
using namespace std;
/*
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's,
empty slots are represented with '.'s. You may assume the following rules:
•You receive a valid board, made of only battleships or empty slots.
•Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape
1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
•At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty())return 0;
        int point = 0, line = 0;
        int row = board.size(), col = board[0].size();
        int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') continue;
                int count = 0;
                for (int k = 0; k < 4; ++k) {
                    int tempx = i + dx[k], tempy = j + dy[k];
                    if (tempx >= 0 && tempx < row&&tempy >= 0 && tempy < col&&board[tempx][tempy] == 'X')
                        ++count;
                }
                if (count == 0) point += 1;
                else if (count == 1) line += 1;
            }
        }
        return point + line / 2;
    }
};

int main() {
    Solution s;
    vector<vector<char>> vec = {
        {'X','.','.','X'},
        {'.','.','.','X'},
        {'.','.','.','X'}
    };
    cout << s.countBattleships(vec) << endl;
}