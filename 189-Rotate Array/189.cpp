#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
[show hint]
Related problem: Reverse Words in a String II
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    void rotate2(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> vec;
        for (int i = nums.size() - k; i < nums.size(); ++i)
            vec.push_back(nums[i]);
        for (int i = nums.size() - 1; i >= k; --i)
            nums[i] = nums[i - k];
        for (int i = 0; i < k; ++i)
            nums[i] = vec[i];
    }
    void rotate3(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> vec;
        for (int i = nums.size() - k; i < nums.size(); ++i)
            vec.push_back(nums[i]);
        for(int i=0;i<nums.size() - k;++i)
            vec.push_back(nums[i]);
        nums = vec;
    }
};
int main() {
    Solution s;
    vector<int> vec = { 1,2,3,4,5,6,7 };
    s.rotate(vec, 3);
    for (auto &v : vec)
        cout << v << " ";
    cout << endl;
    system("pause");
    return 0;
}