#include <iostream>
#include <vector>
using namespace std;

/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {      
        vector<int> temp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1 || i == 2)
                temp[i] = i;
            else
                temp[i] = temp[i - 1] + temp[i - 2];
        }
        return temp[n];
    }
    
};
int main()
{    
    Solution s;  
    cout << s.climbStairs(20) << endl;
    system("pause");
}
