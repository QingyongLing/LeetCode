#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, 
provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, 
y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. 
Start is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with 
xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number 
of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to
find the minimum number of arrows that must be shot to burst all balloons.
Example:
Input:
[[10,16], [2,8], [1,6], [7,12]]
Output:
2
Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another
arrow at x = 11 (bursting the other two balloons).
*/

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int result = 0, index = 0;
        while (index < points.size()) {
            pair<int, int> p = points[index++];
            while (index < points.size() && superposition(p, points[index]))++index;
            ++result;
        }
        return result;
    }
private:
    bool superposition(pair<int, int> &standal, pair<int, int> &elem) {
        if (standal.second<elem.first || standal.first>elem.second)
            return false;
        else {
            standal.first = max(standal.first, elem.first);
            standal.second = min(standal.second, elem.second);
            return true;
        }
    }
};
int main() {
    Solution s;
    vector<pair<int, int>> vec = { {10,16},{2,8},{1,6},{7,12} };
    cout << s.findMinArrowShots(vec) << endl;
}
