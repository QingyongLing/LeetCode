﻿#include <iostream>
#include <vector>
using namespace std;
/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, 
excluding [11,22,33,44,55,66,77,88,99])

Hint:
1.A direct way is to use the backtracking approach.
2.Backtracking should contains three states which are (the current number, number of steps to
get that number and a bitmask which represent which number is marked as visited so far in the
current number). Start with state (0,0,0) and count all valid number till we reach number of 
steps equals to 10n.
3.This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
4.Let f(k) = count of numbers with unique digits with length equals k.
5.f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> num;
        if (n > 0) num.push_back(9);
        if (n > 1) {
            for (int i = 1; i < n&&i < 10;++i) 
                num.push_back(num.back()*(10 - i));
        }
        int result = 0;
        for (int i : num) result += i;
        return result + 1;
    }
};

int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2) << endl;
    return 0;
}