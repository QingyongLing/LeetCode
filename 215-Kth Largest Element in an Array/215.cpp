#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    int findKthLargest2(vector<int>& nums, int k) {
        int size = nums.size();
        auto compsmaller = [](int a, int b) {return a < b; };
        auto compbigger = [](int a, int b) {return a > b; };
        if (k < size / 2) {
            make_heap(nums.begin(), nums.end(), compsmaller);
            for (int i = 0; i < k; ++i)
                pop_heap(nums.begin(), nums.end() - i, compsmaller);
            return nums[nums.size() - k];
        }
        else
        {
            make_heap(nums.begin(), nums.end(), compbigger);
            for (int i = 0; i <= nums.size() - k; ++i)
                pop_heap(nums.begin(), nums.end() - i, compbigger);
            return nums[k - 1];
        }
    }
private:
    int KthLagest(vector<int>& nums, int lo, int hi, int k) {

    }
};
int main() {
    Solution s; 
    vector<int> vec = { 3,2,1,5,6,4 };
    cout << s.findKthLargest2(vec, 5) << endl;
    system("pause");
    return 0;
}