#include <iostream>
#include <vector>
using namespace std;
/*
Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located 
at some specific row R and column C that align with all the following rules:
1.Row R and column C both contain exactly N black pixels.
2.For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
Example:
Input:
[['W', 'B', 'W', 'B', 'B', 'W'],
['W', 'B', 'W', 'B', 'B', 'W'],
['W', 'B', 'W', 'B', 'B', 'W'],
['W', 'W', 'B', 'W', 'B', 'W']]
N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index
0    [['W', 'B', 'W', 'B', 'B', 'W'],
1     ['W', 'B', 'W', 'B', 'B', 'W'],
2     ['W', 'B', 'W', 'B', 'B', 'W'],
3     ['W', 'W', 'B', 'W', 'B', 'W']]
row index
Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels.
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.
Note:
1.The range of width and height of the input 2D array is [1,200].
*/
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty())return 0;
        int row = picture.size(), col = picture[0].size(), count = 0;
        vector<int> rowcount(row), colcount(col);
        for (int i = 0; i < row; ++i) {
            int temp = 0;
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B')
                    ++temp;
            }
            rowcount[i] = temp;
        }
        for (int j = 0; j < col; ++j) {
            int temp = 0;
            for (int i = 0; i < row; ++i) {
                if (picture[i][j] == 'B')
                    ++temp;
            }
            colcount[j] = temp;
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rowcount[i] == N&&colcount[j] == N) {
                    bool add = true;
                    for (int k = 0; k < row; ++k) {
                        if (picture[k][j] == 'B'&&picture[k] != picture[i]) {
                            add = false;
                            break;
                        }
                    }
                    if (add)++count;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<char>> vec = {
    {'W', 'B', 'W', 'B', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'B', 'W'},
    {'W', 'W', 'B', 'W', 'B', 'W'}
    };
    cout << s.findBlackPixel(vec, 3) << endl;
    return 0;
}