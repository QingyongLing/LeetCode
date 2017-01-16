#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty()) return 0;
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> map;
            int vertical = 0, same = 0, tempmax = 0;
            for (int j = 0; j < points.size(); ++j) {
                if (i != j) {
                    int dx = points[i].x - points[j].x;
                    int dy = points[i].y - points[j].y;
                    if (dx) {
                        tempmax = max(tempmax, ++map[static_cast<double>(dy) / dx]);
                    }
                    else {
                        if (dy)++vertical;
                        else ++same;
                    }
                }
            }
            result = max(result, max(tempmax, vertical) + same);
        }
        return result + 1;
    }
};
int main() {
    return 0;
}
