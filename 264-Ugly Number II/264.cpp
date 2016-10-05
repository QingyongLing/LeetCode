#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number.
Hint:
1.The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
2.An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
3.The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
4.Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    //every number should multiply 2 3 5
    int nthUglyNumber(int n) {
        int n2 = 0, n3 = 0, n5 = 0, index = 0;
        vector<int> result(n);
        result[0] = 1;
        for(int i=1;i<n;++i) {
            result[i] = min(result[n2] * 2, min(result[n3] * 3, result[n5] * 5));
            if (result[i] == result[n2] * 2) ++n2;
            if (result[i] == result[n3] * 3) ++n3;
            if (result[i] == result[n5] * 5) ++n5;     
        }
        return result.back();
    }
};
int main() {    
    Solution s;
    cout << s.nthUglyNumber(10) << endl;
    system("pause");
    return 0;
}