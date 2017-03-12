#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a picture consisting of black and white pixels, find the number of black lonely pixels.
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.
Example:
Input:
[['W', 'W', 'B'],
['W', 'B', 'W'],
['B', 'W', 'W']]
Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:
1.The range of width and height of the input 2D array is [1,500].
*/
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
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
                if (rowcount[i] == 1 && colcount[j] == 1 && picture[i][j] == 'B')
                    ++count;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<char>> vec = { {'W','W','B'},{ 'W','B','W' },{ 'B','W','W' } };
    cout << s.findLonelyPixel(vec);
    return 0;
}
