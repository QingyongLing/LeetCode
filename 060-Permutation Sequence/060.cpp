#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
The set [1,2,3,бн,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {      
        vector<bool> selectnum(n, false);
        string result;
        k -= 1;
        for (int i = n; i >= 1; --i)
        {
            int temp = factorial(i - 1);
            int index = k / temp;
            push_char(selectnum, result, index);
            k -= index*temp;
        }
        return result;
    }
    int factorial(int n)
    {
        int num = 1;
        for (int i = 2; i <= n; ++i)
            num *= i;
        return num;
    }
    void push_char(vector<bool> &selectnum, string &str, int next)
    {
        for (int i = 0; i < selectnum.size(); ++i)
        {
            if (!selectnum[i])
            {
                if (!next)
                {
                    str.push_back('1' + i);
                    selectnum[i] = true;
                    break;
                }
                --next;
            }
        }
    }

};


int main()
{
    Solution s;
    cout << s.getPermutation(3, 5) << endl;
    system("pause");
}
