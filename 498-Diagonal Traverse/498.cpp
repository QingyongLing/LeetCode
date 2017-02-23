#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
Example:
Input:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:
Note:
1.The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        if (matrix.empty())return answer;
        int M = matrix.size(), N = matrix[0].size();
        bool up = true;
        for (int total = 0; total < M + N - 1; ++total) {
            int x = 0, y = 0;
            if (up) {
                x = min(M - 1, total);
                y = total - x;
            }
            else {
                y = min(N - 1, total);
                x = total - y;
            }
            while (x > -1 && y > -1 && x < M&&y < N)
                answer.push_back(up ? matrix[x--][y++] : matrix[x++][y--]);
            up = !up;
        }
        return answer;
    }
};
int main() {
    Solution s;
    vector<vector<int>> mat = { {1,2,3} };
    for (auto i : s.findDiagonalOrder(mat))
        cout << i << "  ";
    return 0;
}
