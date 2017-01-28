#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
/*
Given a string of numbers and operators, return all possible results from computing all the different 
possible ways to group numbers and operators. The valid operators are +, - and *.
Example 1
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]
Example 2
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/

class Solution {
public:
    //It seems all testcases are non-negative.
    vector<int> diffWaysToCompute(string input) {
        auto iter = find_if(input.begin(), input.end(), [](char c){ return !isdigit(c); });
        if (iter == input.end())
            return vector<int>(1, stoi(input));
        vector<int> result;
        for (int i = 0; i < input.size(); ++i){
            if (isdigit(input[i])) continue;
            vector<int>  left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for (auto &l : left){
                for (auto &r : right)
                    if (input[i] == '*')
                        result.push_back(l*r);
                    else if (input[i] == '+')
                        result.push_back(l+r);
                    else
                        result.push_back(l-r);
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    for (auto i : s.diffWaysToCompute("2*3-4*5"))
        cout << i << "  ";
    return 0;
}