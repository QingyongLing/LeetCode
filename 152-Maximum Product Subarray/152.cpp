#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0], maxproduct = nums[0], minproduct = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tempmax = maxproduct, tempmin = minproduct;
            maxproduct = max(max(tempmax*nums[i], tempmin*nums[i]), nums[i]);
            minproduct = min(min(tempmax*nums[i], tempmin*nums[i]), nums[i]);
            result = max(result, maxproduct);
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1,0,-1,2,3,-5,-2 };
    cout << s.maxProduct(vec) << endl;
    system("pause");
    return 0;
}