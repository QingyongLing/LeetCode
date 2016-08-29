#include <iostream>
#include <vector>
using namespace std;
/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
    [1],
   [1,1],
  [1,2,1],
 [1,3,3,1],
[1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0)
            return result;
        addlevel(result, 1, numRows);
        return result;
    }
    void addlevel(vector<vector<int>>& result, int level, int numrows) {        
        if(level<=numrows){
            if (level == 1) {
                result.push_back({ 1 });
            }
            else {
                vector<int> temp;
                vector<int> &lastlevel = result.back();
                temp.push_back(lastlevel.front());
                for (int i = 0; i < lastlevel.size() - 1; ++i) {
                    temp.push_back(lastlevel[i] + lastlevel[i + 1]);
                }
                temp.push_back(lastlevel.back());
                result.push_back(temp);
            }
            addlevel(result, level + 1, numrows);
        }
    }
};
int main()
{  
    Solution s;
    auto result = s.generate(5);
    for (auto &c : result) {
        for (auto &v : c)
            cout << v << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}
