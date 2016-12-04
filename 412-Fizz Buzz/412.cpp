#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples
of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
Example:
n = 15,
Return:
[
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14",
"FizzBuzz"
]
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> strs;
        for (int i = 1; i <= n; ++i) {
            bool multhree = (i % 3 == 0);
            bool mulfive = (i % 5 == 0);
            if (multhree&&mulfive)
                strs.push_back("FizzBuzz");
            else if(multhree)
                strs.push_back("Fizz");
            else if(mulfive)
                strs.push_back("Buzz");
            else {
                strs.push_back(to_string(i));
            }
        }
        return strs;
    }
};

int main() {
    Solution s;
    for (auto &str : s.fizzBuzz(15))
        cout << str << "  ";
    return 0;
}