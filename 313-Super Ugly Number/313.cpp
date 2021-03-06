﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]  is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    struct Elem
    {
        int nextUglynum, index, prime;
        Elem():nextUglynum(0), index(0), prime(0){}
    };
    //slower orz
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        vector<Elem> uglynums(primes.size());
        for (int i = 0; i < primes.size(); ++i) {
            uglynums[i].nextUglynum = primes[i];
            uglynums[i].prime = primes[i];
        }
        int cur = 0;
        vector<int> result(n);
        auto cmp = [](Elem &a, Elem &b) { return a.nextUglynum > b.nextUglynum; };
        make_heap(uglynums.begin(), uglynums.end(), cmp);
        for (int i = 1; i < n; ++i) {
            int temp = uglynums.front().nextUglynum;
            if (cur == temp) --i;
            else result[i] = temp;
            cur = temp;
            pop_heap(uglynums.begin(), uglynums.end(), cmp);
            Elem &last = uglynums.back();
            last.nextUglynum = result[++last.index] * last.prime;
            push_heap(uglynums.begin(), uglynums.end(), cmp);
        }
        return result.back();
    }
    int nthSuperUglyNumber2(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0), result(n, INT_MAX);
        result[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < index.size(); ++j) 
                result[i] = min(result[i], primes[j] * result[index[j]]);            
            for (int j = 0; j < index.size(); ++j)
                if (result[i] == primes[j] * result[index[j]]) ++index[j];
        }
        return result.back();
    } 

};
int main() {   
    vector<int> vec = { 2, 7, 13, 19 };
    Solution s;
    cout << s.nthSuperUglyNumber(12, vec) << endl;
    return 0;
}