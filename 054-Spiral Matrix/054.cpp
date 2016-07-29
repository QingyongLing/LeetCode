#include <iostream>
#include <vector>
using namespace std;
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]. */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()!=0)
            clockwiseoutput(matrix, result, 0, matrix[0].size() - 1);
        return result;
    }
    void clockwiseoutput(vector<vector<int>>& matrix, vector<int> &result, int top, int right)
    {       
        int M = matrix.size();
        int N = matrix[0].size(); 
        int bottom = M - top - 1;
        int left = N - 1 - right;
        if (top > bottom|| right < left)
        {
            return;
        }     
        for (int i = left; i <= right; ++i)
            result.push_back(matrix[left][i]);
        for (int i = top + 1; i < bottom; ++i)
            result.push_back(matrix[i][right]);
        if (top != bottom)
        {
            for (int i = right; i >= top; --i)
                result.push_back(matrix[bottom][i]);
        }
        if (right!= left)
        {
            for (int i = bottom - 1; i > top; --i)
                result.push_back(matrix[i][left]);
        }
        clockwiseoutput(matrix, result, top + 1, right - 1);
    }
};
int main()
{  
    Solution s;
    //vector<vector<int>> vec = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    vector<vector<int>> vec = { {1,3}, {2,4} };
    auto result = s.spiralOrder(vec);
    for (auto &c : result)
        cout << c;
    cout << endl;
    system("pause");
    return 0;
}
