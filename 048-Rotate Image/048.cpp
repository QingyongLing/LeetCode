#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
*/
class Solution {
public:
    void rotateclockwise(int start, vector<vector<int>> &matrix)
    {
        int N = matrix.size();
        for (int i = start; i < N - start - 1; ++i)
        {
            swap(matrix[start][i], matrix[i][N - start - 1]);
            swap(matrix[start][i], matrix[N - start - 1][N - 1 - i]);
            swap(matrix[start][i], matrix[N - 1 - i][start]);
        }   
    }
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix.size();
        if (num == 1)
            return;
        else
        {
            num /= 2;
            for (int i = 0; i < num; ++i)
                rotateclockwise(i, matrix);
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> vec = { { 1,2,3,3 },{4,5,6,6},{7,8,9,9},{0,1,2,2} };
    for (auto &v : vec)
    {
        for (auto &c : v)
            cout << c << " ";
        cout << endl;
    }
    cout << "--------------------" << endl;
    s.rotate(vec);
    for (auto &v : vec)
    {
        for (auto &c : v)
            cout << c << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
