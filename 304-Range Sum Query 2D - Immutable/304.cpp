#include <iostream>
#include <vector>
using namespace std;
/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
Example:
Given matrix = [
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
1.You may assume that the matrix does not change.
2.There are many calls to sumRegion function.
3.You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        sum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            sum[i][0] = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                sum[i][j + 1] = sum[i][j] + matrix[i][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int num = 0;
        for (int i = row1; i <= row2; ++i) {
            num += sum[i][col2 + 1] - sum[i][col1];
        }
        return num;
    }
private:
    vector<vector<int>> sum;
};
int main() {   
    vector<vector<int>> vec = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5} };
    NumMatrix s(vec);
    cout << s.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}