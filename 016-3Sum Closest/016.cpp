/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    author=Ling
    date=2016.5.22
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[nums.size() - 1];
        int distance = abs(target - result);
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int temp = nums[i] + nums[j] + nums[k];
                int sub = target - temp;
                if (abs(sub) < distance)
                {
                    result = temp;
                    distance = abs(sub);
                }
                if (sub > 0)
                {
                    ++j;continue;
                }
                else if (sub < 0)
                {
                    --k; continue;
                }
                else
                    return target;
            }
        }
        return result;
    }
};
int main() {
  Solution s;
  vector<int> vec = { 0, 2, 1, -3 };
  cout << s.threeSumClosest(vec, 1) << endl;
  return 0;
}
