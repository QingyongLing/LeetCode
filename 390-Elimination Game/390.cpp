#include <iostream>
using namespace std;
/*
There is a list of sorted integers from 1 to n. Starting from left to right, remove the first
number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the right most number
and every other number from the remaining numbers.
We keep repeating the steps again, alternating left to right and right to left, until a single 
number remains.
Find the last number that remains starting with a list of length n.
Example:
Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6
Output:
6
*/

class Solution {
public:
    int lastRemaining(int n) {
        int result = 1, sub = 0;
        bool left = true;
        while (n != 1) {
            if (n % 2 == 0 && !left) sub += result;
            n /= 2;
            result *= 2;
            left = !left;
        }
        return result - sub;
        //or
        //return untilesigle(n, true);
    }
private:
    int untilesigle(int n, bool left) {
        if (n == 1) return 1;
        if (!left&&n % 2 == 0)
            return 2 * untilesigle(n / 2, !left) - 1;
        else
            return 2 * untilesigle(n / 2, !left);
    }
};

int main() {
    Solution s;
    cout << s.lastRemaining(90) << endl;
    return 0;
}