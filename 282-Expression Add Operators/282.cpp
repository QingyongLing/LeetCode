#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add
binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
Credits:
Special thanks to @davidtan1890 for adding this problem and creating all test cases.
*/

class Solution {
public:
    //From: http://www.cnblogs.com/grandyang/p/4814506.html
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        addOperatorsimpl(answer, num, 0, 0, target, "");
        return answer;
    }
private:
    void addOperatorsimpl(vector<string> &answer, string &next, int lastnum, int curnum, int target, string output){
        if (next.empty() && curnum == target){
            answer.push_back(output);
            return;
        }
        for (int i = 1; i <= next.size(); ++i){
            string cur = next.substr(0, i), newnext = next.substr(i);
            if (cur.size() > 1 && cur[0] == '0')return;
            if (i > 10 || (i == 10 && cur > string("2147483647")))return;
            int num = stoi(cur);
            if (!output.empty()){
                addOperatorsimpl(answer, newnext, num, curnum + num, target, output + "+" + cur);
                addOperatorsimpl(answer, newnext, -num, curnum - num, target, output + "-" + cur);
                addOperatorsimpl(answer, newnext, lastnum*num, (curnum - lastnum) + lastnum*num, target, output + '*' + cur);
            }
            else{
                addOperatorsimpl(answer, newnext, num, num, target, cur);
            }
        }
    }
};
int main(){
    Solution s;
    for (auto &str : s.addOperators("123", 6))
        cout << str << endl;
    return 0;
}