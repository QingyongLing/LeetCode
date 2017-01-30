#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for the first two numbers, 
each subsequent number in the sequence must be the sum of the preceding two.
For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199. 1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
Follow up:
How would you handle overflow for very large input integers?
Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; ++i){
            for (int j = 1; j <= (num.size() - i) / 2; ++j){
                if (valid(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;
            }
        }
        return false;
    }
private:
    bool valid(string num1, string num2, string num3){
        if ((num1.size() != 1 && num1[0] == '0') || (num2.size() != 1 && num2[0] == '0') || num3.empty())return false;
        string sum = stradd(num1, num2);
        if (sum == num3)return true;
        if (num3.size() < sum.size() || num3.substr(0, sum.size()) != sum)return false;
        else return valid(num2, sum, num3.substr(sum.size()));
    }
    string stradd(string &m, string &n){
        int flag = 0, i = m.size() - 1, j = n.size() - 1;
        string res;
        while (i >= 0 || j >= 0){
            int sum = flag + (i >= 0 ? (m[i--] - '0') : 0) + (j >= 0 ? (n[j--] - '0') : 0);
            flag = sum / 10;
            res.push_back(sum - flag * 10 + '0');
        }
        if (flag)res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    Solution s;
    cout << s.isAdditiveNumber("199100199") << endl;
    return 0;
}