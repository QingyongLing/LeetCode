/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.

Author=Ling
Date=2016.5.29
*/
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
class Solution {
public:
    //Runtime: 8 ms
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        if (abs(divisor) == 1)
            return divisor > 0 ? dividend : (dividend == -1 - INT_MAX ? INT_MAX : -dividend);
        bool divleft = dividend < 0 ? true : false;
        bool divright = divisor < 0 ? true : false;
        long long absdividend = dividend;
        long long absdivisor = divisor;
        absdividend = abs(absdividend);
        absdivisor = abs(absdivisor);
        if (absdivisor>absdividend)
            return 0;
        int i = 0;
        vector<long long> data;
        long long temp = 0;
        while (absdividend > temp)
        {
            temp = absdivisor << i;
            ++i;
            data.push_back(temp);
        }
        auto binary_search_ = [&data](int num)->int
        {
            int left = 0, right = data.size() - 1, mid = 0;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (data[mid] <= num)
                {
                    if (data[mid + 1] > num)
                        break;
                    left = mid;
                    continue;
                }
                else
                {
                    right = mid;
                    continue;
                }
            }
            return mid;
        };
        int result = 0;
        while (absdividend >= absdivisor)
        {
            int temp = binary_search_(absdividend);
            result += 1 << temp;
            absdividend -= data[temp];
        }
        return divleft^divright ? -result : result;
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    int temp=-1-INT_MAX;
    cout<<s.divide(temp, temp)<<endl;
    return 0;
}
