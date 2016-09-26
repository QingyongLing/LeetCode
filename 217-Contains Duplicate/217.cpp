#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto &n : nums) {
            if (hashset.find(n) != hashset.end())
                return true;
            else
                hashset.insert(n);
        }
        return false;
    }
};
int main() {
    Solution s; 
    
    system("pause");
    return 0;
}