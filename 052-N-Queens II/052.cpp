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
        vector<bool> QueensCol(n,false);
        int total = 0;
        vector<bool> lefttop(2 * n - 1, false);
        vector<bool> righttop(2 * n - 1, false);
        placeQueens(total, QueensCol, lefttop, righttop, 0, n);
        return total;
    }
    void placeQueens(int& total, vector<bool> &QueensCol, vector<bool> &lefttop, vector<bool> &righttop, int row, int n)
    {
        if (row == n)
        {
            ++total;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {               
                if (!(QueensCol[i]|| lefttop[n-1-row+i]||righttop[row+i]))
                {
                    QueensCol[i] = lefttop[n - 1 - row + i] = righttop[row + i] = true;
                    placeQueens(total, QueensCol, lefttop, righttop, row + 1, n);
                    QueensCol[i] = lefttop[n - 1 - row + i] = righttop[row + i] = false;
                }
            }
        }
    }

    int totalNQueens_inc(int n) {
        if (n == 0 || n == 2)
            return 0;
        //false is just comment
        bool QueensCol[100] = { false };
        int total = 0;
        bool lefttop[100] = { false };
        bool righttop[100] = { false };
        placeQueens_inc(total, QueensCol, lefttop, righttop, 0, n);
        return total;
    }
    void placeQueens_inc(int& total, bool *QueensCol, bool *lefttop, bool* righttop, int row, int n)
    {
        if (row == n)
        {
            ++total;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (!(QueensCol[i] || lefttop[n - 1 - row + i] || righttop[row + i]))
                {
                    QueensCol[i] = lefttop[n - 1 - row + i] = righttop[row + i] = true;
                    placeQueens_inc(total, QueensCol, lefttop, righttop, row + 1, n);
                    QueensCol[i] = lefttop[n - 1 - row + i] = righttop[row + i] = false;
                }
            }
        }
    }

    int totalNQueens2(int n) {
        if (n == 0 || n == 2)
            return 0;
        vector<int> QueensCol;
        int total = 0;
        placeQueens2(total, QueensCol, 0, n);
        return total;
    }
    void placeQueens2(int& total, vector<int> &QueensCol, int row, int n)
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
                    placeQueens2(total, QueensCol, row + 1, n);
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
