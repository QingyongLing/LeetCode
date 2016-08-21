#include <iostream>
#include <vector>
using namespace std;
/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        vector<int>::iterator left = nums.begin(), right = nums.end() - 1;
        vector<int>::iterator temp = nums.begin();
        while (1)
        {
            while (left<nums.end()&&*left == 0)
                ++left;
            while (right >= nums.begin() && *right == 2)
                --right;
            if (left >= right)
                break;
            if (*left != 1 || *right != 1)
                swap(*left, *right);
            else
            {
                if (temp <= left)
                    temp = left + 1;
                while (temp < nums.end() && *temp == 1)
                    ++temp;
                if (temp >= right || temp == nums.end())
                    break;
                if (*temp == 0)
                    swap(*left, *temp);
                else if (*temp == 2)
                    swap(*temp, *right);
            }
        }
    }
};
int main()
{  
    Solution s;
    vector<int> vec = {  };
    s.sortColors(vec);
    for (auto &c : vec)
        cout << c << " ";
    cout << endl;
    system("pause");
    return 0;
}
