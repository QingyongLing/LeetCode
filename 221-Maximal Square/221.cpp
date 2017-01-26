#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and 
return its area.
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())return 0;
        int row = matrix.size(), col = matrix[0].size(), result = 0;
        vector<vector<int>> flag(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (matrix[i][j] == '1'){
                    if (i == 0 || j == 0)
                        flag[i][j] = 1;
                    else
                        flag[i][j] = min(min(flag[i - 1][j], flag[i - 1][j - 1]), flag[i][j - 1]) + 1;
                    result = max(flag[i][j], result);
                }
            }
        }
        return  result*result;
    }
};
int main() {
    Solution s;
    return 0;
}