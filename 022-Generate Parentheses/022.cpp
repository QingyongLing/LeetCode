#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    //Runtime:4ms
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0)
            return result;
        int num = 2 * n;
        int maxbinary = 1 << num;
        string str(num, ' ');
        for (int binarynum = (1 << (num-1)); binarynum < maxbinary; binarynum += 2)
        {
            int left = 0;
            for (int j = num-1; j >= 0; --j)
            {
                //(-->1 )-->0
                int bit = (binarynum >> j) & 1;
                bit ? ++left : --left;
                if (left < 0)
                    break;
            }
            if (left == 0)
            {
                for (int j = 0; j < num; ++j)
                {
                    int bit = (binarynum >> j) & 1;
                    str[num - j - 1] = bit ? '(' : ')';
                }
                result.push_back(str);
            }
        }
        return result;
    }

    //copy from https://leetcode.com/discuss/86372/c-0ms-recursive-solution-with-explanation?show=86372#q86372
    //Runtime:0ms   amazing
    vector<string> generateParenthesis2(int n) {
        vector<string> result;
        if (n == 0)
            return result;
        string s("(");
        gen(&result, s, 1, n);
        return result;
    }
    void gen(vector<string> * result, string s, int open, int n)
    {
        if (s.size() == 2 * n)
            (*result).push_back(s);
        else
        {
            if (open < 2 * n - s.size())
            {
                string s2(s);
                s2.push_back('(');
                gen(result, s2, open + 1, n);
            }
            if (open > 0)
            {
                s.push_back(')');
                gen(result, s, open - 1, n);
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto c = s.generateParenthesis2(3);
    for (auto &d : c)
        cout << d << endl;
    c = s.generateParenthesis(3);
    for (auto &d : c)
        cout << d << endl;
    return 0;
}
