#include <iostream>
#include <vector>
using namespace std;
/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the 
little match girl has, please find out a way you can make one square by using up all 
those matchsticks. You should not break any stick, but you can link them up, and each 
matchstick must be used exactly one time.
Your input will be several matchsticks the girl has, represented with their stick length.
Your output will either be true or false, to represent whether you could make one square 
using all the matchsticks the little match girl has.
Example 1:
Input: [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks 
with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
1.The length sum of the given matchsticks is in the range of 0 to 10^9.
2.The length of the given matchstick array will not exceed 15.
*/

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4)
            return false;
        int sum = 0;
        for (int i : nums)sum += i;
        if (sum % 4)return false;
        sum /= 4;
        return dividetwopart(nums, sum);
    }
private:
    bool dividetwopart(vector<int>& nums, int squarelen) {
        int sum = 0, tempsum = 0;
        for (int i : nums)sum += i;
        if (sum % 2)return false;
        vector<int> flag(nums.size(), 0), first;
        sum /= 2;
        tempsum += nums[0];
        flag[0] = 1;
        first.push_back(nums[0]);
        return dfs(nums, flag, first, 1, tempsum, sum, squarelen);
    }
    bool dfs(vector<int>& nums, vector<int> &flag, vector<int>& first, int cur, int sum, int target, int squarelen) {
        if (sum > target)return false;
        if (sum == target) return true;
        for (int i = cur; i < nums.size(); ++i) {
            if (flag[i] == 0) {
                sum += nums[i];
                first.push_back(nums[i]);
                flag[i] = 1;
                bool equal = dfs(nums, flag, first, i + 1, sum, target, squarelen);
                if (equal) {
                    if (target == squarelen)
                        return true;
                    vector<int> second;
                    for (int j = 0; j < nums.size(); ++j) {
                        if (flag[j] == 0)
                            second.push_back(nums[j]);
                    }
                    if (dividetwopart(first, squarelen) && dividetwopart(second, squarelen))
                        return true;
                }
                flag[i] = 0;
                first.pop_back();
                sum -= nums[i];
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> vec{ 5,5,5,5,4,4,4,4,3,3,3,3 };
    cout << s.makesquare(vec);
}
