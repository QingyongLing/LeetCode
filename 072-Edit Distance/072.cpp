#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.size();
        const int len2 = word2.size();
        vector<vector<int> > f(len1 + 1, vector<int>(len2 + 1));
        for (int i = 0; i <= len1; ++i) {
            f[i][0] = i;
        }
        for (int j = 0; j <= len2; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j) {
                if (word2[j - 1] == word1[i - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                }
                else {
                    int tmp = min(f[i][j - 1], f[i - 1][j]);
                    f[i][j] = min(f[i - 1][j - 1], tmp) + 1;
                }
            }
        return f[len1][len2];
    }
};

int main() {
    Solution s;
    string str1("geek"), str2("gesek");
    cout << s.minDistance(str1, str2)<< endl;   
    system("pause");
    return 0;
}