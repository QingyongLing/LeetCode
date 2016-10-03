#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
using namespace std;
/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].
Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
Follow up:
Could you solve it in linear time?
Hint:
1.How about using a data structure such as deque (double-ended queue)?
2.The queue size need not be the same as the window’s size.
3.Remove redundant elements and the queue should store only elements that need to be considered.
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> index;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (index.empty())
                index.push_back(i);
            else {
                while (!index.empty() && nums[index.back()] < nums[i])
                    index.pop_back();
                index.push_back(i);
                if (i - index.front() > k - 1)
                    index.pop_front();
            }
            if (i >= k - 1)
                result.push_back(nums[index.front()]);
        }
        return result;
    }
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        multiset<int> window;
        for (int i = 0; i < k - 1; ++i) {
            window.insert(nums[i]);
        }
        vector<int> result;
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);
            result.push_back(*(--window.end()));
            auto iter = window.find(nums[i - k + 1]);
            window.erase(iter);
        }
        return result;
    }
};
int main() {    
    Solution s;
    vector<int> vec = { -7,-8,7,5,7,1,6,0 };
    for (auto &c : s.maxSlidingWindow(vec, 4))
        cout << c << " ";
    cout << endl;
    system("pause");
    return 0;
}