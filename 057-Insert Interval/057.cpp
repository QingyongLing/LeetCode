#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
class Solution {
public:
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}        
    };
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return result;
        }
        auto left = find(intervals, newInterval.start);
        auto right = find(intervals, newInterval.end);
        //添加left前面部分
        if (left.first != 0)
            for_each(intervals.begin(), intervals.begin() + left.first, [&result](Interval& elem) {result.push_back(elem); });       
        Interval temp(0, 0);
        temp.start = left.second ? intervals[left.first].start : newInterval.start;
        if (right.first == intervals.size())
            temp.end = newInterval.end;
        else
            temp.end = right.second ? intervals[right.first].end : newInterval.end;
        result.push_back(temp);
        //添加right后面不受影响的部分
        if (right.first != intervals.size())
        {
            if (!right.second)
                result.push_back(intervals[right.first]);
            for_each(intervals.begin() + right.first + 1, intervals.end(), [&result](Interval& elem) {result.push_back(elem); });
        }return result;
    }
    pair<int, bool> find(vector<Interval>& intervals, int num)
    {
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (num >= intervals[i].start&&num <= intervals[i].end)
                return make_pair(i, true);
            if (num < intervals[i].start)
                return make_pair(i, false);
        }
        return make_pair(intervals.size(), false);
    }

    //我怎么会写这么恶心的分类讨论的代码
    vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        auto left = find_if(intervals.begin(), intervals.end(),
            [&newInterval](Interval& a) { return newInterval.start <= a.start; });
        auto right = find_if(intervals.begin(), intervals.end(),
            [&newInterval](Interval& a) { return newInterval.end <= a.start; });
        if (left == intervals.begin())
        {
            if (right == intervals.begin())
            {
                result.push_back(newInterval);
                for_each(intervals.begin(), intervals.end(), [&result](Interval& elem) {result.push_back(elem); });
            }
            else if (right == intervals.end())         
                result.push_back(Interval(newInterval.start,max(intervals.back().end, newInterval.end)));           
            else
            {
                result.push_back(Interval(newInterval.start, max((right-1)->end, newInterval.end)));
                for_each(right, intervals.end(), [&result](Interval& elem) {result.push_back(elem); });
            }
        }
        else if (left == intervals.end())
        {
            result = intervals;
            if (intervals.size()==0|| intervals.back().end<newInterval.start)
            {
                result.push_back(newInterval);
            }
            else
            {
                result.back().end=max(newInterval.end, intervals.back().end);
            }
        }
        else
        {
            for_each(intervals.begin(), left - 1, [&result](Interval& elem) {result.push_back(elem); });
            Interval temp(0, 0);
            if ((left - 1)->end < newInterval.start)
            {
                result.push_back(*(left - 1));
                temp.start = newInterval.start;
            }
            else
            {
                temp.start = (left - 1)->start;
            }
            if (right == intervals.end())
            {  
                temp.end = max(intervals.back().end, newInterval.end);
                result.push_back(temp);
            }
            else
            {
                temp.end = max((right-1)->end, newInterval.end);
                result.push_back(temp);
                for_each(right, intervals.end(), [&result](Interval& elem) {result.push_back(elem); });
            }
        }
        return result;
    }

};
int main()
{  
    Solution s;
    vector<Solution::Interval> vec = { {1,5} };
    auto result = s.insert(vec, {2,3});
    for (auto &c : result)
    {
        cout << "[" << c.start << "," << c.end << "] ";
    }
    system("pause");
    return 0;
}
