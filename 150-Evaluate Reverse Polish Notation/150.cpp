#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        string str = "+-*/";
        for (auto &elem : tokens) {
            int index = str.find(elem);
            if (index!=string::npos) {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                switch (index)
                {
                case 0:
                    nums.push(num1 + num2); break;
                case 1:
                    nums.push(num1 - num2); break;
                case 2:
                    nums.push(num1 * num2); break;
                case 3:
                    nums.push(num1 / num2); break;              
                }
            }
            else {
                nums.push(stoi(elem));
            }
        }
        return nums.top();
    }
};
int main() {
    Solution s;
    //注意vec=["0","3"，"/"]的情况，除法除以0的情况
    vector<string> vec = { "2", "1", "+", "3", "*" };
    cout << s.evalRPN(vec) << endl;
    system("pause");
    return 0;
}