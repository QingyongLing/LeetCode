#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid
(well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
    //using stack
    int longestValidParentheses(string s) {
        stack<int> stk;
        int result = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                if (stk.empty()) {
                    start = i + 1;
                }
                else {
                    stk.pop();
                    if (stk.empty())
                        result = max(result, i - start + 1);
                    else
                        result = max(result, i - stk.top());
                }
            }
        }
        return result;
    }
    //DP
    //https://discuss.leetcode.com/topic/2426/my-dp-o-n-solution-without-using-stack
    int longestValidParentheses2(string s) {
        if (s.size() < 2)return 0;
        vector<int> dp(s.size(), 0);
        int result = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i > 1) ? dp[i - 2] + 2 : 2;
                else {
                    if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                }
                result = max(dp[i], result);
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    cout << s.longestValidParentheses2(")()())") << endl;
}
