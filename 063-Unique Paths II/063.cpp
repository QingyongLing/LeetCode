#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

/*
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        if (M == 0)
            return 0;
        int N = obstacleGrid[0].size();
        vector<vector<int>> resultnums(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (i == 0 && j == 0 && obstacleGrid[0][0] == 0)
                {
                    resultnums[0][0] = 1;
                    continue;
                }
                int num = 0;
                if (i - 1 >= 0 && obstacleGrid[i - 1][j] == 0)
                    num += resultnums[i - 1][j];
                if (j - 1 >= 0 && obstacleGrid[i][j - 1]==0)
                    num += resultnums[i][j - 1];
                if (obstacleGrid[i][j] == 0)
                    resultnums[i][j] = num;
            }
        }
        return resultnums[M - 1][N - 1];
    }
};
int main()
{    
    Solution s;  
    vector<vector<int>> vec = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
    cout << s.uniquePathsWithObstacles(vec) << endl;
    system("pause");
}
