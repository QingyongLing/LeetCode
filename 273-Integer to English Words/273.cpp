#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less 
than 231 - 1.
For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:
1.Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
2.Group the number by thousands (3 digits). You can write a helper function that takes a number less than 
1000 and convert just that chunk to words.
3.There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 
1000010? (middle chunk is zero and should not be printed out)
*/

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)return "Zero";
        string answer, str = to_string(num), unit[] = { "", "Thousand ", "Million ", "Billion " };
        int len = str.size();
        for (int i = 3; i >= 0; --i){
            if (len > i * 3){
                int left = 0;
                if (len > 3 * (i + 1))
                    left = str.size() - 3 * (i + 1);
                string temp = word(str, left, len - i * 3 - 1);
                if (!temp.empty())
                    answer.append(temp).append(unit[i]);
            }
        }
        answer.pop_back();
        return answer;
    }
private:
    string word(string &str, int left, int right){
        static string num[] = { "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine " };
        static string tens[] = { "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };
        static string teen[] = { "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
        string answer;
        if (right - left == 2 && str[right - 2] != '0')
            answer.append(num[str[right - 2] - '1']).append("Hundred ");
        if (right - left >= 1 && str[right - 1] != '0'){
            if (str[right - 1] == '1'&&str[right] != '0'){
                answer.append(teen[str[right] - '1']);
                return answer;
            }
            answer.append(tens[str[right - 1] - '1']);
        }
        if (str[right] != '0')
            answer.append(num[str[right] - '1']);
        return answer;
    }
};
int main(){
    Solution s;
    cout << s.numberToWords(2147483647) << endl;
    return 0;
}