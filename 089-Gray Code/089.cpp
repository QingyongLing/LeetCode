#include <iostream>
#include <vector>
using namespace std;
/*
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n == 0)
            return result;
        backtracking(result, n, true, 0);
        return result;
    }
    void backtracking(vector<int>& result, int k,bool f, int num)
    {
        if (k == 0)
            result.push_back(num);
        else
        {
            int temp;
            temp = (1 << (k - 1));
            if (f)
            {
                backtracking(result, k - 1, f, num);
                backtracking(result, k - 1, !f, num | temp);               
            }
            else
            {
                backtracking(result, k - 1, !f, num | temp);
                backtracking(result, k - 1, f, num);                
            }
        }
    }
};
int main()
{  
    Solution s;
    auto vec = s.grayCode(3);
    for (auto &c : vec)
        cout << c << " ";
    system("pause");
    return 0;
}
