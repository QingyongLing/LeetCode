#include <iostream>
#include <vector>
using namespace std;
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
Note:
You can assume that you can always reach the last index.
*/
class Solution {
public:
    vector<int>::iterator find(vector<int>::iterator start)
    {
        int maxnum = 0, num = *start++;
        vector<int>::iterator temp;
        for (int i = 1; i <= num;++start,++i)
        {
            if (maxnum < *start + i)
            {
                maxnum = *start + i;
                temp = start;
            }
        }
        return temp;
    }
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int jumpnum = 0;
        int count = 0;
        vector<int>::iterator temp=nums.begin();
        while (1)
        {
            ++jumpnum;
            if (temp + *temp + 1 >= nums.end())
                return jumpnum;
            temp = find(temp);
        }
        return jumpnum;
    }
};
int main()
{
    Solution s;
    vector<int> vec = { 1,1,1,1,4 };
    cout << s.jump(vec)<<endl;
    system("pause");
    return 0;
}
