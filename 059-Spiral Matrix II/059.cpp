#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example,
Given n = 3,
You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0)
            return vector<vector<int>>();
        vector<int> temp(n, 0);
        vector<vector<int>> result(n,temp);
        int num = 1;
        fill(result, 0, num);
        return result;
    }
    void fill(vector<vector<int>>& result, int row,int& num)
    {
        int N = result.size();
        int maxcol = N - 1 - row;
        if (maxcol == row)
            result[row][row] = num++;
        else if (row < maxcol)
        {
            for (int i = row; i < maxcol; ++i)
                result[row][i] = num++;
            for (int i = row; i < maxcol; ++i)
                result[i][maxcol] = num++;
            for (int i = maxcol; i > row; --i)
                result[maxcol][i] = num++;
            for (int i = maxcol; i > row; --i)
                result[i][row] = num++;
            fill(result, row + 1, num);
        }
        else
            return;
    }
};


int main()
{
    Solution s;
    auto result=s.generateMatrix(4);
    for (auto &v : result)
    {
        for (auto &c : v)
            cout << c << " ";
        cout << endl;
    }
    system("pause");
}
