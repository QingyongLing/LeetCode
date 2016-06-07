/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 

Author=Ling
Date=2016.6.7
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if (height.size() <= 1)
            return result;
        stack<int> keepheight,left;
        int right = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            if (keepheight.empty()||height[i] <= keepheight.top())
            {
                keepheight.push(height[i]);
                left.push(i);
            }
            else
            {
                int temp = 0;
                do
                {
                    temp = keepheight.top();
                    keepheight.pop();
                    left.pop();
                    if (keepheight.empty())break;
                    if (keepheight.top() < height[i])
                        result += (i - left.top() - 1)*(keepheight.top() - temp);
                    else
                        result += (i - left.top() - 1)*(height[i] - temp);
                } while (keepheight.top() <= height[i]);
                keepheight.push(height[i]);
                left.push(i);
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> v = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << s.trap(v);
    return 0;
}