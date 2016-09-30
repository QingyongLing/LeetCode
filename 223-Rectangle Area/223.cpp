#include <iostream>
#include <algorithm>
using namespace std;
/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A == C || B == D) return (G - E)*(H - F);
        if (E == G || F == H) return (C - A)*(D - B);
        int sum = (G - E)*(H - F) + (C - A)*(D - B);
        return sum - coincidence(A, C, E, G)*coincidence(B, D, F, H);
    }
private:
    int coincidence(int n1, int n2, int m1, int m2) {
        if (m2 <= n1)
            return 0;
        else if (m1 <= n1)
            return min(m2 - n1, n2 - n1);
        else if (m1 >= n2)
            return 0;
        else return min(m2 - m1, n2 - m1);
    }
};
int main() {
    Solution s;
    cout << s.computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl;
    system("pause");
    return 0;
}