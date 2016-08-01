#include <iostream>
using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int maxnum = max(m, n);
        int minnum = min(m, n);
        return factorial(m + n - 2, maxnum - 1) / (factorial(minnum - 1));
    }
    long long factorial(int n,int m=1)
    {
        long long num = 1;
        for (int i = m + 1; i <= n; ++i)
            num *= i;
        return num;
    }
};


int main()
{
    Solution s;
    cout << s.uniquePaths(1, 100) << endl;
    system("pause");
}
