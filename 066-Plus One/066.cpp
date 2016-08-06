#include <iostream>
#include <vector>
using namespace std;

/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0)
            return digits;
        vector<int> result = digits;
        reverse(result.begin(), result.end());
        bool add = true;
        for (int i = 0; i < result.size(); ++i)
        {
            if (add)
            {
                int temp = result[i] + 1;
                if (temp == 10)
                {
                    result[i] = 0;
                }
                else
                {
                    result[i] += 1;
                    add = false;
                }
            }
            else
                break;
        }
        if (add)
            result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{    
    Solution s;  
    vector<int> vec = { 0 };
    int num = 100;
    while (num--)
    {
        for (auto &c : vec)
            cout << c;
        cout << endl;
        vec = s.plusOne(vec);
    }
    system("pause");
}
