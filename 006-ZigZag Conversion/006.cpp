#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    //20 ms    Your runtime beats 52.60% of cppsubmissions
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int num = (s.size() - 1) / (numRows - 1);
        if (num == 0)
            return s;
        num = num*(numRows - 1);
        vector<int> index( s.size(),-1);
        for (int i = numRows-1; i < num; i+=numRows-1)
        {
            for (int j = 1; j < numRows; ++j)
                index[i - j] = i + j;
        }
        for (int i = num, j = 1; i + j < s.size(); ++j)
        {
            index[i - j] = i + j;
        }
        string ans;
        for (int i = 0; i < numRows&&i < s.size(); ++i)
        {
            int temp = i;
            do
            {
                ans.append(1,s[temp]);
                temp = index[temp];
            }
            while (temp!=-1);
        }
        return ans;
    }
    //16 ms   Your runtime beats 70.79% of cppsubmissions
    string convert2(string s, int numRows)
    {
        if (numRows == 1 || s.size() <= numRows)
            return s;
        string ans(s.size(),' ');
        int index = 0;
        for (int i = 0; i < numRows; ++i)
        {
            int temp = i;
            int incre = 2 * (numRows - 1) - i * 2;
            do
            {
                if (incre == 0)
                    incre = 2 * (numRows - 1) - incre;
                ans[index++] = s[temp];
                temp += incre;
                incre = 2 * (numRows - 1) - incre;
            }
            while (temp<s.size());
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "PAYPALISHIRING";
    cout << s.convert2(str, 3)<<endl;
    str = "PAY";
    cout << s.convert2(str, 3)<<endl;
    str = "P";
    cout << s.convert2(str, 3) << endl;
    str = "ABC";
    cout << s.convert2(str, 2) << endl;
}
