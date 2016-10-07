﻿#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.
Hint:
1.An easy approach is to sort the array first.
2.What are the possible values of h-index?
3.A faster approach is to use extra space.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        unordered_map<int, int> map;
        for (auto i : citations)
            map[i]++;
        int size = citations.size(), count = 0, result = 0;
        for (int i = 0; i <= size; ++i) {
            if (size - count >= i) {
                count += map[i];
                result = i;
            }
            else break;
        }
        return result;
    }
};
int main() {    
    Solution s;
    vector<int> vec = { 3, 0, 6, 1, 5 };
    cout << s.hIndex(vec) << endl;
    system("pause");
    return 0;
}