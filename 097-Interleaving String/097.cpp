#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    //dp
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> flag(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 0; i < flag.size(); ++i) {
            for (int j = 0; j < flag[0].size(); ++j) {
                if (i == 0 && j == 0)
                    flag[i][j] = 1;
                else {
                    if (j > 0 && flag[i][j - 1] && s3[i + j - 1] == s2[j - 1])
                        flag[i][j] = 1;
                    if (i > 0 && flag[i - 1][j] && s3[i + j - 1] == s1[i - 1])
                        flag[i][j] = 1;
                }
            }
        }
        return flag[s1.size()][s2.size()];
    }
    
    //回溯，Time Limit Exceeded 
    bool isInterleave2(string s1, string s2, string s3) {
        if (s1.empty())
            return s2 == s3;
        else if (s2.empty())
            return s1 == s3;
        else
            return backtracking(s1, s2, s3, 0, 0, 0);
    }
    bool backtracking(string &s1, string &s2, string &s3, int i1, int i2, int i3) {
        if (s3.size()-1 == i3) {
            if (i2 == s2.size() && i1 == s1.size() - 1 && s3[i3] == s1[i1])
                return true;
            if (i1 == s1.size() && i2 == s2.size() - 1 && s3[i3] == s2[i2])
                return true;
            return false;
        }if (i1 > s1.size() || i2 > s2.size())
            return false;
        else {
            if (s1[i1] == s3[i3] && backtracking(s1, s2, s3, i1 + 1, i2, i3 + 1))
                return true;
            if (s2[i2] == s3[i3] && backtracking(s1, s2, s3, i1, i2 + 1, i3 + 1))
                return true;
            return false;
        }
    }
};
int main()
{  
    Solution s;
    cout << (s.isInterleave("aabcc", "dbbca", "aadbbcbcac") ? "true" : "false") << endl;
    system("pause");
    return 0;
}
