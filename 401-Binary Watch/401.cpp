#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent 
the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible
times the watch could represent.
Example:
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
•The order of output does not matter.
•The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
•The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, 
it should be "10:02".
*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> time{ 1,2,4,8,1,2,4,8,16,32 }, chosen;
        vector<string> result;
        backtracking(result, time, chosen, 0, num);
        return result;
    }
private:
    void backtracking(vector<string>& result, vector<int> &time, vector<int> &chosen, int index,int num) {
        if (chosen.size() == num) {
            int hour = 0, minute = 0;
            for (int i : chosen) {
                if (i < 4)hour += time[i];
                else minute += time[i];
            }
            if (hour > 11 || minute > 59) return;
            string str;
            if (hour)str.append(to_string(hour));
            else str.push_back('0');
            str.push_back(':');
            if (minute == 0)
                str.append("00");
            else {
                if (minute < 10)
                    str.push_back('0');
                str.append(to_string(minute));
            }
            result.push_back(str);
        }
        else {
            for (int i = index; i < time.size(); ++i) {
                chosen.push_back(i);
                backtracking(result, time, chosen, i + 1, num);
                chosen.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    for (auto &s : s.readBinaryWatch(1))
        cout << s << "  ";
    return 0;
}