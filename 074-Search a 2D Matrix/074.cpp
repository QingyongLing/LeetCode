#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
•Integers in each row are sorted from left to right.
•The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:
[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.

*/

class Solution {
public:
    int row = matrix.size(), col = matrix[0].size();
        int lo = 0, hi = row*col - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int num = getelem(mid, matrix);
            if (num > target)
                hi = mid - 1;
            else if (num < target)
                lo = mid + 1;
            else return true;
        }
        return false;
    }
private:
    int getelem(int index, vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        return matrix[index / col][index%col];
    }
};
int main()
{  
    Solution s;
    vector<vector<int>> vec = {{-8, -7, -5, -3, -3, -1, 1}, {2, 2, 2, 3, 3, 5, 7},
    {8, 9, 11, 11, 13, 15, 17}, {18, 18, 18, 20, 20, 20, 21}, {23, 24, 26, 26, 26, 27, 27},
    {28, 29, 29, 30, 32, 32, 34}};
    cout << (s.searchMatrix(vec, -5) ? "true" : "false") << endl;
    system("pause");
    return 0;
}
