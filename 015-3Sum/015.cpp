/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

•Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
•The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        vector<int> usenum;
        usenum.reserve(nums.size());
        sort(nums.begin(), nums.end());
        int last=nums[0],temp = 1;
        usenum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            temp = last == nums[i] ? temp + 1 : (last = nums[i], 1);
            if (nums[i] != 0 && temp < 3)
                usenum.push_back(nums[i]);
            if (nums[i] == 0 && temp <= 3)
                usenum.push_back(nums[i]);
        }
        if (usenum.size() < 3)
            return result;
        vector<int> tempvec(3,0);
        for (int i = 0; i < usenum.size() - 2; ++i)
        {
            if (usenum[i]>0)
                break;
            if (i>0 && usenum[i] == usenum[i - 1])
                continue;
            int j = i + 1;
            int k = usenum.size() - 1;
            while (j < k)
            {
                if (j > i + 1 && usenum[j] == usenum[j - 1])
                {
                    ++j; continue;
                }
                if (k + 1 < usenum.size() - 1 && usenum[k] == usenum[k + 1])
                {
                    --k; continue;
                }
                if (usenum[i] + usenum[j] + usenum[k] < 0)
                {
                    ++j; continue;
                }
                if (usenum[i] + usenum[j] + usenum[k] > 0)
                {
                    --k; continue;
                }
                if (usenum[i] + usenum[j] + usenum[k] == 0)
                {

                    tempvec[0] = usenum[i];
                    tempvec[1] = usenum[j];
                    tempvec[2] = usenum[k];
                    result.push_back(tempvec);
                    ++j;
                    --k;
                }
            }
        }
        return result;
    }
};
int main() {
  Solution s;
  vector<int> vec={-1, 0, 1, 2, -1, -4};
  auto result=s.threeSum(vec);
  for (auto &c : result)
  {
          for (auto &d : c)
              cout << d << " ";
          cout << endl;
  }
  return 0;
}
