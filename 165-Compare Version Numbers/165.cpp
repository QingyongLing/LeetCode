#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        split(vec1, version1, '.');
        split(vec2, version2, '.');
        while (vec1.back() == 0)
            vec1.pop_back();
        while (vec2.back() == 0)
            vec2.pop_back();
        for (int i = 0; i < vec1.size() && i < vec2.size(); ++i) {
            if (vec1[i] > vec2[i])
                return 1;
            else if (vec1[i] < vec2[i])
                return -1;
        }
        if (vec1.size() == vec2.size())
            return 0;
        return vec1.size() > vec2.size() ? 1 : -1;
    }
private:
    void split(vector<int>& vec, string &str, char c) {
        size_t left = 0, right = 0;
        while (right != string::npos) {
            right = str.find(c, left);
            if(right == string::npos)
                vec.push_back(stoi(string(str.begin() + left, str.end())));
            else
                vec.push_back(stoi(string(str.begin() + left, str.begin() + right)));           
            left = right + 1;
        }
    }
};
int main() {
    Solution s;
    string s1("01.0"), s2("1.0.1");
    cout << s.compareVersion(s1, s2) << endl;
    system("pause");
    return 0;
}