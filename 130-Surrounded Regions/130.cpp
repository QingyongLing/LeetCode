#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
*/
class Solution {
public:
    //union-find
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        row = board.size(), col = board[0].size();
        if (row < 3 || col < 3)
            return;
        vector<int> id(row*col, 0);       
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int cur = i*col + j;
                id[cur] = cur;
                if (i > 0&&board[i][j]=='O'&&board[i-1][j]=='O') {
                    uniontwopos(id, cur, cur - col);
                }
                if (j > 0 && board[i][j] == 'O'&&board[i][j - 1] == 'O') {
                    uniontwopos(id, cur, cur - 1);
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O' && !isonborder(findroot(id, i*col + j)))
                    board[i][j] = 'X';
            }
        }
    }
    //use bfs
    void solve2(vector<vector<char>>& board) {
        if (board.empty())
            return;
        row = board.size(), col = board[0].size();
        if (row < 3 || col < 3)
            return;
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O') bfs(board, 0, i);
            if (board[row - 1][i] == 'O') bfs(board, row - 1, i);
        }
        for (int i = 1; i < row - 1; ++i) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][col - 1] == 'O') bfs(board, i, col - 1);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '*') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    //use dfs
    void solve3(vector<vector<char>>& board) {
        if (board.empty())
            return;
        row = board.size(), col = board[0].size();
        if (row < 3 || col < 3)
            return;
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[row - 1][i] == 'O') dfs(board, row - 1, i);
        }
        for (int i = 1; i < row - 1; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][col - 1] == 'O') dfs(board, i, col - 1);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '*') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
private:
    int row, col;
    int findroot(vector<int>& id, int p) { 
        int r = p;
        while (r != id[r])
            r = id[r];
        int temp;
        while (p != id[p]) {
            temp = p;
            p = id[p];
            id[temp] = r;
        }
        return r;
    }
    void uniontwopos(vector<int>& id, int p, int q) {
        int i = findroot(id, p);
        int j = findroot(id, q);
        bool flagi = isonborder(i), flagj = isonborder(j);
        if (flagi && !flagj) {
            id[j] = i;      
        }
        else{
            id[i] = j;            
        }      
    }
    bool isonborder(int p) {
        return p / col == 0 || p / col == row - 1 || p%col == 0 || p%col == col - 1;
    }

    void bfs(vector<vector<char>>& board,int x,int y) {
        deque<pair<int, int>> nextposition;
        int incx[] = { 0,1,0,-1 };
        int incy[] = { 1,0,-1,0 };
        board[x][y] = '*';
        nextposition.push_back(make_pair(x, y));
        while (!nextposition.empty()) {
            int frontx = nextposition.front().first;
            int fronty = nextposition.front().second;
            for (int i = 0; i < 4; ++i) {
                int tempx = frontx + incx[i];
                int tempy = fronty + incy[i];
                if (tempx >= 0 && tempx < row&&tempy >= 0 && tempy < col&&board[tempx][tempy] == 'O') {
                    board[tempx][tempy] = '*';
                    nextposition.push_back(make_pair(tempx, tempy));
                }                   
            }           
            nextposition.pop_front();
        }
    }
    
    void dfs(vector<vector<char>>& board, int x, int y) {
        stack<pair<int, int>> nextposition;
        int incx[] = { 0,1,0,-1 };
        int incy[] = { 1,0,-1,0 };
        board[x][y] = '*';
        nextposition.push(make_pair(x, y));
        while (!nextposition.empty()) {
            int frontx = nextposition.top().first;
            int fronty = nextposition.top().second;
            nextposition.pop();
            for (int i = 0; i < 4; ++i) {
                int tempx = frontx + incx[i];
                int tempy = fronty + incy[i];
                if (tempx >= 0 && tempx < row&&tempy >= 0 && tempy < col&&board[tempx][tempy] == 'O') {
                    board[tempx][tempy] = '*';
                    nextposition.push(make_pair(tempx, tempy));
                }
            }        
        }
    }
};
int main() {
    Solution s;
    vector<vector<char>> board = {
        { 'X','O','X','X' },
        { 'X','O','X','O' },
        { 'O','X','O','X' },
        { 'X','O','X','O' },
        { 'O','X','O','X' } };
    s.solve(board);
    for (auto &s : board) {
        for (auto &c : s)
            cout << c << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}