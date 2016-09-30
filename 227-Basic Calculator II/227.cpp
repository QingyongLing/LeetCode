#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    int calculate(string s) {
        int index = 0, len = s.size();
        vector<char> ops;
        vector<int> nums;
        while (index < len) {
            if (s[index] == ' ') {
                ++index;
                continue;
            }
            if (isnum(s[index])) {               
                nums.push_back(getnum(index, s));
            }
            else if(s[index]=='*'|| s[index] == '/'){
                char c = s[index];
                int num = getnum(++index, s);
                int temp = nums.back();
                nums.pop_back();
                temp = c == '*' ? (temp*num) : (temp / num);
                nums.push_back(temp);
            }
            else {
                ops.push_back(s[index++]);
            }
        }
        int result = nums.front();
        for (int i = 0; i < ops.size(); ++i) {
            result = ops[i] == '+' ? (result + nums[i + 1]) : (result - nums[i + 1]);
        }
        return result;
    }
private:
    int getnum(int &index, string &s) {
        while (s[index] == ' ')++index;
        int num = 0;
        while (isnum(s[index])) {
            num = num * 10 + (s[index] - '0');
            ++index;
        }
        return num;
    }
    bool isnum(char c) {
        return c <= '9'&&c >= '0' ? true : false;
    }
};
int main() {
    Solution s;
    cout << s.calculate(" 3+5 / 2 ") << endl;
    system("pause");
    return 0;
}