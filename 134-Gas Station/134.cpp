#include <iostream>
#include <vector>
using namespace std;
/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {     
        int sum = 0;
        int  start = 0, subsum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            int temp = gas[i] - cost[i];
            sum += temp;
            subsum += temp;
            if (subsum < 0) {
                subsum = 0;
                start = i + 1;
            }
        }
        return sum < 0 ? -1 : start;
    }
};
int main() {
    Solution s;
    vector<int> gas = { 1,4,3,4,10,4,6 };
    vector<int> cost = { 3,5,2,5,6,5,6 };
    cout << s.canCompleteCircuit(gas, cost) << endl;
    system("pause");
    return 0;
}