#include <iostream>
#include <vector>
using namespace std;
/*
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].
Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        PascalRow(result, rowIndex);
        return result;
    }
    void PascalRow(vector<int> &row, int rowindex) {
        if (rowindex == 0) {
            row[0] = 1;
        }else{
            PascalRow(row, rowindex - 1);
            for (int i = rowindex; i > 0; --i) {
                row[i] = row[i] + row[i - 1];
            }
        }
    }
};
int main()
{  
    Solution s;
    auto result = s.getRow(3);
    for (auto &c : result) {
        cout << c << " ";        
    }
    system("pause");
    return 0;
}
