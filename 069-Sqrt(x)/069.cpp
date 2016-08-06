#include <iostream>
#include <vector>
using namespace std;

/*
Implement int sqrt(int x).
Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 0, right = x, mid = x / 2;
        long long temp = 0;
        while (left < right)
        {
            temp = mid;
            temp = temp*temp;
            if (temp == x)
                return mid;
            else if (temp > x)
                right = mid - 1;
            else
                left = mid + 1;
            mid = (left + right) / 2;
        }
        temp = mid;
        temp = temp*temp;
        return temp > x ? mid - 1 : mid;
    }
};
int main()
{    
    Solution s;  
    vector<int> vec = { 0, 1, 2, 4, 6, 8, 9, 10, 24, 38, 2147395599 };
    for (auto &c : vec)
    {
        cout << s.mySqrt(c) << endl;
    }
    system("pause");
}
