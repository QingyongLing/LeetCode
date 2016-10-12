#include <iostream>
#include <vector>
using namespace std;
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
1.You may assume that the array does not change.
2.There are many calls to sumRange function.
*/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int num = 0;
        sum.push_back(num);
        for (int i = 0; i < nums.size(); ++i) {
            num += nums[i];
            sum.push_back(num);
        }
    }
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};
int main() {   
    vector<int> vec = { -2, 0, 3, -5, 2, -1 };
    NumArray s(vec);
    cout << s.sumRange(0, 5) << endl;
    return 0;
}