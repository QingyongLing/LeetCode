#include <iostream>
#include <vector>
using namespace std;
/*
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
public:

    int totalNQueens(int n) {
        if (n == 0 || n == 2)
            return 0;
        vector<int> QueensCol;
        int total = 0;
        placeQueens(total, QueensCol, 0, n);
        return total;
    }
    void placeQueens(int& total, vector<int> &QueensCol, int row, int n)
    {
        if (row == n)
        {
            ++total;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                bool Noconflict = true;
                for (int j = 0; j < QueensCol.size(); ++j)
                {
                    if (i == QueensCol[j] || row - j == abs(i - QueensCol[j]))
                    {
                        Noconflict = false;
                        break;
                    }
                }
                if (Noconflict)
                {
                    QueensCol.push_back(i);
                    placeQueens(total, QueensCol, row + 1, n);
                    QueensCol.pop_back();
                }
            }
        }
    }   
};
int main()
{
    Solution s;
    auto result = s.totalNQueens(5);
    cout << result << endl;
    system("pause");
    return 0;
}
