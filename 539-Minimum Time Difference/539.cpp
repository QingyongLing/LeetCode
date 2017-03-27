#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any 
two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
1.The number of time points in the given list is at least 2 and won't exceed 20000.
2.The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (int i = 0; i < timePoints.size(); ++i) {
            size_t index = timePoints[i].find(':');
            int h = stoi(timePoints[i].substr(0, index));
            int m = stoi(timePoints[i].substr(index + 1, timePoints[i].size() - index - 1));
            minutes.push_back(60 * h + m);
        }
        sort(minutes.begin(), minutes.end());
        int answer = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            answer = min(answer, minutes[i] - minutes[i - 1]);
        }
        answer = min(answer, 24 * 60 - minutes.back() + minutes[0]);
        return answer;
    }
};

int main() {
    Solution s;
    vector<string> str = { "23:59", "00:14","0:19","0:9","0:8" };
    cout << s.findMinDifference(str) << endl;
    return 0;
}