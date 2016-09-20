#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
Description:
Count the number of prime numbers less than a non-negative number, n.
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
class Solution {
public:
    int countPrimes(int n) {       
        int result = 0;
        for (int i = 2; i < n; ++i)
            if (isprime(i))++result;
        return result;
    }
private:
    bool isprime(int n) {
        if (n == 1) return false;
        if (n == 2 || n == 3 || n == 5)
            return true;
        if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
            return false;
        int maxc = sqrt(n);
        unsigned int c = 7;
        while (c <= maxc) {
            if (n%c == 0)
                return false;
            c += 4;
            if (n%c == 0)
                return false;
            c += 2;
            if (n%c == 0)
                return false;
            c += 4;
            if (n%c == 0)
                return false;
            c += 2;
            if (n%c == 0)
                return false;
            c += 4;
            if (n%c == 0)
                return false;
            c += 6;
            if (n%c == 0)
                return false;
            c += 2;
            if (n%c == 0)
                return false;
            c += 6;
        }
        return true;
    }
};
int main() {
    Solution s; 
    system("pause");
    return 0;
}