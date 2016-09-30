#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
/*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
You may assume that the given expression is always valid.
Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/
class Solution {
public:
    int calculate(string s) {
        int index = s.size() - 1;
        stack<int> nums;
        stack<char> operators;
        while (index >= 0) {
            if (s[index] == ' ') {
                --index;
                continue;
            }
            if (s[index] == ')'|| s[index] == '+'|| s[index] == '-') {
                operators.push(s[index--]);
                continue;
            }
            else if (s[index] == '(') {
                count(nums, operators);
                --index;
            }
            else
                addnumber(index, s, nums);
        }
        if (!operators.empty()) 
            count(nums, operators);
        return nums.top();
    }
private:
    void count(stack<int> &nums, stack<char> &operators) {
        int temp = nums.top();
        nums.pop();
        while (!nums.empty() && !operators.empty() && operators.top() != ')') {
            int right = nums.top();
            nums.pop();
            if (operators.top() == '+')
                temp += right;
            if (operators.top() == '-')
                temp -= right;
            operators.pop();
        }
        if (!operators.empty() && operators.top() == ')')
            operators.pop();
        nums.push(temp);
    }
    void addnumber(int &index,string &s,stack<int> &nums) {
        int num = 0;
        while (index >= 0 && s[index] <= '9'&&s[index] >= '0') {
            ++num;
            --index;
        }
        nums.push(stoi(s.substr(index + 1, num)));
    }
};
int main() {
    Solution s;
    cout << s.calculate("(1 + (4 + 5 + 2 ) - 3 ) + ( 6 + 8 )") << endl;
    system("pause");
    return 0;
}