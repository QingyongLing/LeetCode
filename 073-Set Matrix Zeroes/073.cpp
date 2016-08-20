#include <iostream>
#include <vector>
using namespace std;
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
click to show follow up.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        bool flagrow0 = false, flagcol0 = false;
        for (int i = 0; i < row; ++i)
        {
            if (matrix[i][0] == 0)
                flagcol0 = true;
        }
        for (int i = 0; i < col; ++i)
        {
            if (matrix[0][i] == 0)
                flagrow0 = true;
        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
            }
        }
        for (int i = 1; i < row; ++i)
        {
            if (matrix[i][0] == 0)
                setrowzeroes(matrix, i);
        }
        for (int i = 1; i < col; ++i)
        {
            if (matrix[0][i] == 0)
                setcolzeroes(matrix, i);
        }
        if(flagcol0)
            setcolzeroes(matrix, 0);
        if (flagrow0)
            setrowzeroes(matrix, 0);
    }
    void setcolzeroes(vector<vector<int>>& matrix, int col)
    {
        int row = matrix.size();
        for (int i = 0; i < row; ++i)
            matrix[i][col] = 0;
    }
    void setrowzeroes(vector<vector<int>>& matrix, int row)
    {
        int col = matrix[0].size();
        for (int i = 0; i < col; ++i)
            matrix[row][i] = 0;
    }
};
int main()
{  
    Solution s;
    vector<vector<int>> vec = { {0, 0, 0, 5},{4, 3, 1, 4},{0, 1, 1, 4},{1, 2, 1, 3},{0, 0, 1, 1} };
    for (auto &c : vec)
    {
        for (auto &v : c)
            cout << v << " ";
        cout << endl;
    }
    s.setZeroes(vec);
    for (auto &c : vec)
    {
        for (auto &v : c)
            cout << v << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
