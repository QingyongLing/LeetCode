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
    int x1, x2, y1, y2;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        x1 = y1 = 0;
        x2 = matrix.size() - 1;
        y2 = matrix[0].size() - 1;
        while (x1 <= x2&&y1 <= y2)
        {
            x2 = colbinarysearch(matrix, target, y1);
            y1 = rowbinarysearch(matrix, target, x2);
            x1 = colbinarysearch(matrix, target, y2);
            y2 = rowbinarysearch(matrix, target, x1);
            if (x1 == x2&& y1 == y2)
            {
                if (target == matrix[x1][y1])
                    return true;
                break;
            }
            if (x1 <= x2 - 1 && y1 <= y2 - 1)
                break;
        }
        if (matrix[x1][y1] == target || matrix[x2][y1] == target || matrix[x1][y2] == target || matrix[x2][y2] == target)
            return true;
        else
            return false;
    }
    //find the first value bigger than target
    //use upper_bound may be better
    int rowbinarysearch(vector<vector<int>>& matrix, int target,int row)
    {
        int left = y1, right = y2, mid;
        if (matrix[row][right] <= target)
            return right;
        if (matrix[row][left] >= target)
            return left;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (mid != 0 && matrix[row][mid] >= target&&matrix[row][mid - 1] < target)
                return mid;
            if (matrix[row][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
    //find the first value bigger than target
    //use upper_bound may be better
    int colbinarysearch(vector<vector<int>>& matrix, int target, int col)
    {
        int top = x1, bottom = x2, mid;
        if (matrix[bottom][col] <= target)
            return bottom;
        if (matrix[top][col] >= target)
            return top;
        while (top < bottom)
        {
            mid = (top + bottom) / 2;
            if (mid != 0 && matrix[mid][col] >= target&&matrix[mid - 1][col] < target)
                return mid;
            if (matrix[mid][col] > target)
                bottom = mid - 1;
            else
                top = mid + 1;
        }
        return bottom;
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
