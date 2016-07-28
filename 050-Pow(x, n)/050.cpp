#include <iostream>
using namespace std;
/*
Implement pow(x, n).
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        double result = 1.0;
        if (n == INT_MIN)
        {
            fun(x, result, INT_MAX);
            result *= x;
        }
        else
        {
            fun(x, result, abs(n));
        }     
        return n>0 ? result : 1.0/result;
    }
    void fun(double x, double& result, int n)
    {
        if (n == 0)
            return;
        if (n % 2 == 0)
            fun(x*x, result, n / 2);
        else
        {
            result *= x;
            fun(x, result, n - 1);
        }
    }
};
int main()
{
    Solution s;
    cout << s.myPow(1.0, INT_MIN) << endl;
    system("pause");
    return 0;
}
