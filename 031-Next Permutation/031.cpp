/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Author=Ling
Date=2016.6.1
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int maxnum = *nums.rbegin();
        auto first = find_if(nums.rbegin(), nums.rend(), [&maxnum](int &num)
        { return num < maxnum ? true : (maxnum = num, false); });
        if (first == nums.rend())
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            auto second = find_if(nums.rbegin(), first, [&first](int &num)
            {return num > *first; });
            swap(*first, *second);
            sort(nums.rbegin(), first, [](int &a, int &b){return a > b; });
        }
    }
};
int main()
{
    Solution s;
    vector<int> v = { 1, 1, 3, 4 };
    for (int i = 0; i < 26; ++i)
    {
        s.nextPermutation(v);
        for (auto &c : v)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
