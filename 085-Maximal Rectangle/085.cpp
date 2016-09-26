#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        vector<vector<int>> col(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> row = col;
        vector<vector<pair<int, int>>> area;
        int maximal = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            vector<pair<int, int>> temp;
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                int width = 0, height = 0;
                if (i == 0)
                    col[i][j] = matrix[i][j] - '0';
                else
                    col[i][j] = matrix[i][j] == '0' ? 0 : col[i - 1][j] + 1;
                if (j == 0)
                    row[i][j] = matrix[i][j] - '0';
                else
                    row[i][j] = matrix[i][j] == '0' ? 0 : row[i][j - 1] + 1;
                if (i == 0 || j == 0)
                {
                    width = row[i][j];
                    height = col[i][j];
                }
                else
                {
                    int width1, width2, height1, height2;
                    if (matrix[i][j] == '1')
                    {
                        if (area[i - 1][j].first != 0)
                            width1 = min(area[i - 1][j].first, row[i][j - 1] + 1);
                        else
                            width1 = row[i][j - 1] + 1;
                        height1 = area[i - 1][j].second + 1;
                        if (temp[j - 1].second != 0)
                            height2 = min(temp[j - 1].second, col[i - 1][j] + 1);
                        else
                            height2 = col[i - 1][j] + 1;
                        width2 = temp[j - 1].first + 1;
                        if (width1*height1 > width2*height2)
                        {
                            width = width1;
                            height = height1;
                        }
                        else
                        {
                            width = width2;
                            height = height2;
                        }
                    }
                }
                temp.push_back(make_pair(width, height));
                int rectarea = width*height;
                if (rectarea > maximal)
                    maximal = rectarea;
            }
            area.push_back(temp);
        }
        return maximal;
    }
};
int main()
{  
    Solution s;
    vector<vector<char>> vec = {
        { '0','1','1','0','1' },
        { '1','1','0','1','0' },
        { '0','1','1','1','0' },
        { '1','1','1','1','0' },
        { '1','1','1','1','1' },
        { '0','0','0','0','0' } };
    cout << s.maximalRectangle(vec) << endl;
    system("pause");
    return 0;
}
