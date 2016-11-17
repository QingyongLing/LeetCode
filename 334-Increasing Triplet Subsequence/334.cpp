#include <iostream>
#include <vector>
using namespace std;
/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.
Examples:
Given [1, 2, 3, 4, 5],
return true.
Given [5, 4, 3, 2, 1],
return false.
Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lis;
        for (int i : nums) {
            if (lis.empty() || i > lis.back())
                lis.push_back(i);
            else {
                for (int &n : lis) {
                    if (n >= i) {
                        n = i;
                        break;
                    }
                }
            }
            if (lis.size() == 3)
                return true;
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1,2,3,4,5 };
    cout << s.increasingTriplet(vec) << endl;
    return 0;
}