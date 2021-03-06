﻿#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
/*
Given an array of integers with possible duplicates, randomly output the index of a given target number.
You can assume that the given target number must exist in the array.
Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/

class Solution {
public:
    Solution(vector<int> nums) {
        num = nums;
        srand(time(NULL));
    }

    int pick(int target) {
        int count = 0, index = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == target) {
                ++count;
                if (count == 1) index = i;
                else {
                    if (rand() % count == 0) index = i;
                }
            }
        }
        return index;
    }
private:
    vector<int> num;
};

int main() {
    vector<int> vec = { 1,2,2,3,3,3 };
    Solution s(vec);
    cout << s.pick(1) << endl;
    return 0;
}