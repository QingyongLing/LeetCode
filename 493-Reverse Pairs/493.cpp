#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
You need to return the number of important reverse pairs in the given array.
Example1:
Input: [1,3,2,3,1]
Output: 2
Example2:
Input: [2,4,3,5,1]
Output: 3
Note:
1.The length of the given array will not exceed 50,000.
2.All the numbers in the input array are in the range of 32-bit integer.
*/

class Solution {
public:
    using veciter = vector<int>::iterator;
    int reversePairs(vector<int>& nums) {
        temp = vector<int>(nums.size());
        int count = 0;
        merge(nums.begin(), nums.end(), count);
        return count;
    }
private:
    vector<int> temp;
    void merge(veciter start, veciter end, int &count) {
        if (end - start < 2)return;
        int dif = end - start;
        veciter mid = start + dif / 2;
        merge(start, mid, count);
        merge(mid, end, count);
        for (veciter iter = mid; iter < end; ++iter) {
            int &n = *iter;
            if (n < 0 && 2 * n>0)
                count += mid - start;
            else if (n > 0 && 2 * n < 0)
                continue;
            else
                count += mid - upper_bound(start, mid, 2 * (*iter));
        }
        int index = 0;
        veciter temps = start, tempm = mid;
        while (1) {
            if (temps < mid&&tempm < end)
                temp[index++] = *temps < *tempm ? *(temps++) : *(tempm++);
            else if (temps == mid&&tempm == end)
                break;
            else
                temp[index++] = temps == mid ? *(tempm++) : *(temps++);
            
        }
        for (int i = 0; i < index; ++i)
            *(start++) = temp[i];
    }
};
int main() {
    Solution s;
    vector<int> vec = { 5,4,3,2,1 };
    cout << s.reversePairs(vec) << endl;
    return 0;
}
