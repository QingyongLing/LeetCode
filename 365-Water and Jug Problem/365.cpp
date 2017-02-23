#include <iostream>
#include <algorithm>
using namespace std;
/*
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available.
You need to determine whether it is possible to measure exactly z litres using these two jugs.
If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
Operations allowed:
•Fill any of the jugs completely with water.
•Empty any of the jugs.
•Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)
Input: x = 3, y = 5, z = 4
Output: True
Example 2:
Input: x = 2, y = 6, z = 5
Output: False
Credits:
Special thanks to @vinod23 for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0)return true;
        if (x + y<z)return false;
        return impl(x, y, z);
    }
    bool impl(int x, int y, int z) {
        if (y == 0 || x == 0)return false;
        if (z%x == 0 || z%y == 0 || z % (x + y) == 0)
            return true;
        return impl(min(x, y), max(x, y) - min(x, y), z);
    }
};
int main() {
    Solution s;
    cout << s.canMeasureWater(6, 9, 1) << endl;
    return 0;
}
