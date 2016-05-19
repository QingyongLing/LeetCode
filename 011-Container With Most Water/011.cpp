
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
//n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).Find two lines,
//which together with x - axis forms a container, such that the container contains the most water.
//Note: You may not slant the container.

class Solution
{
public:
    //Time Limit Exceeded
    int maxArea(vector<int>& height)
    {
        int maxcontainer = 0;
        int last = 0;
        int left = 0, right = height.size() - 1;
        for (int i = 0; i < height.size(); ++i)
        {
            if (height[i]<last)
                left = 0,right=height.size()-1;
            while (height[left] < height[i])
            {
                ++left;
            }
            while (height[right] < height[i])
            {
                --right;
            }
            maxcontainer = max(maxcontainer, max(i - left, right - i)*height[i]);
            last = height[i];
        }
        return maxcontainer;
    }
    int maxArea2(vector<int> &height)
    {
        int left = 0, right = height.size() - 1, maxcontainer = 0;
        while (left < right)
        {
            maxcontainer = max(maxcontainer, (right - left)*min(height[left], height[right]));
            if (height[left]<height[right])
                do
                {
                    ++left;
                }
                while (left<right&&height[left]<=height[left - 1]);
            else
                do
                {
                    --right;
                }
                while (left<right&&height[right]<=height[right + 1]);
        }
        return maxcontainer;
    }
};
int main()
{
    Solution s;
    vector<int> temp= { 1, 2, 3, 1, 1 };
    cout << s.maxArea2(temp);
    return 0;
}
