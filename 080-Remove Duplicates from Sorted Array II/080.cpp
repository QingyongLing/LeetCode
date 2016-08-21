#include <iostream>
#include <vector>
using namespace std;
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int length = 1;
        int last = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == last&&count != 2)
            {
                nums[length] = nums[i];
                ++length;
                ++count;                
            }
            if (nums[i] != last)
            {
                nums[length] = nums[i];
                count = 1;
                last = nums[i];
                ++length;
            }
        }
        return length;
    }
};
int main()
{  
    Solution s;
    vector<int> vec = { 1,1,1,2,2,3 };
    cout << s.removeDuplicates(vec) << endl;
    for (auto &c : vec)
        cout << c << " ";
    system("pause");
    return 0;
}
