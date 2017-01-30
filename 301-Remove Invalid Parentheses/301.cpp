#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Remove the minimum number of invalid parentheses in order to make the input string valid. 
Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ).
Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
Credits:
Special thanks to @hpplayer for adding this problem and creating all test cases.
*/

class Solution {
public:
    //From: https://discuss.leetcode.com/topic/34875/easy-short-concise-and-fast-java-dfs-3-ms-solution
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(s, res, 0, 0, string("()"));
        return res;
    }
private:
    void remove(string &s, vector<string> &res, int last_i, int last_j, string par){
        int cnt = 0, i = last_i;
        for (; i < s.size(); ++i){
            if (s[i] == par[0])++cnt;
            if (s[i] == par[1])--cnt;
            if (cnt < 0)break;
        }
        if (cnt < 0){
            for (int j = last_j; j <= i; ++j){
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])){
                    string next = s.substr(0, j).append(s.substr(j + 1));
                    remove(next, res, i, j, par);
                }
            }
            return;
        }
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        if (par[0] == '(')
            remove(reversed, res, 0, 0, string(")("));
        else
            res.push_back(reversed);
    }
};
int main(){
    Solution s;
    for (auto &str : s.removeInvalidParentheses("(((()())(()"))
        cout << str << endl;
    return 0;
}