#include <iostream>
#include <vector>
using namespace std;
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {        
        if (s.empty())
            return 0;
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] != '0')
                dp[i] += dp[i - 1];
            else if (s[i] != '0')
                dp[i] = 1;
            if (i > 1 && valid(s, i - 1, i))
                dp[i] += dp[i - 2];
            else if (i == 1 && valid(s, i - 1, i))
                dp[i] += 1;
        }
        return dp.back();
    }
    bool valid(string& s, int left, int right){
        if (s[left] == '1')
            return true;
        if (s[left] == '2'&&s[right] <= '6')
            return true;
        return false;
    }
};
int main()
{  
    Solution s;
    cout << s.numDecodings("012321") << endl;
    system("pause");
    return 0;
}
