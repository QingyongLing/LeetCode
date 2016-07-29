#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
using namespace std;
/*
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
class Solution {
public:
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}        
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0)
            return result;
        auto compare = [](Interval &left, Interval& right) {return left.start < right.start; };
        sort(intervals.begin(), intervals.end(), compare);  
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start <= result.back().end)
            {
                if (intervals[i].end > result.back().end)
                    result.back().end = intervals[i].end;
            }
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};
int main()
{  
    Solution s;
    vector<Solution::Interval> vec = { {1,3},{2,6},{8,10},{15,18} };
    auto result = s.merge(vec);
    for (auto &c : result)
    {
        cout << "[" << c.start << "," << c.end << "] ";
    }
    system("pause");
    return 0;
}
