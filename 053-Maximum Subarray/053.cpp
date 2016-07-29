#include <iostream>
#include <vector>
using namespace std;
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.
click to show more practice.
More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsubsum = nums[0];
        int temp = 0;
        for (auto &c : nums)
        {
            temp += c;
            if (temp>maxsubsum)
                maxsubsum = temp;
            if (temp<0)
                temp = 0;
        }
        return maxsubsum;
    }
    //more practice
    //divide and conquer approach
    int maxSubArray2(vector<int>& nums) {
        return maxsub(nums, 0, nums.size() - 1);
    }
    int maxsub(vector<int>& nums, int start, int last)
    {
        if (start == last)
            return nums[start];
        int mid = (start + last) / 2;
        int maxleft = maxsub(nums, start, mid);
        int maxright = maxsub(nums, mid + 1, last);
        int lefthalf = nums[mid];
        int temp = 0;
        for (int i = mid; i >= start; --i)
        {
            temp += nums[i];
            if (temp > lefthalf)
                lefthalf = temp;
        }
        int righthalf = nums[mid+1];
        temp = 0;
        for (int i = mid+1; i <= last; ++i)
        {
            temp += nums[i];
            if (temp > righthalf)
                righthalf = temp;
        }
        return max({ maxleft,maxright,lefthalf + righthalf });
    }
};
int main()
{  
    Solution s;
    vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
    auto result = s.maxSubArray2(vec);
    cout << result << endl;
    system("pause");
    return 0;
}
