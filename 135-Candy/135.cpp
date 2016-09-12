#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
•Each child must have at least one candy.
•Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        vector<int> leftcount(ratings.size(), 0);
        vector<int> rightcount(ratings.size(), 0);
        int temp = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1])
                ++temp;
            else
                temp = 0;          
            leftcount[i] = temp;
        }
        temp = 0;
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                ++temp;
            else
                temp = 0;          
            rightcount[i] = temp;
        }
        int result = 0;
        for (int i = 0; i < leftcount.size(); ++i) {
            result += max(leftcount[i], rightcount[i]);
        }
        return result + leftcount.size();
    }
};
int main() {
    Solution s;
    vector<int> ratings = { 1, 2, 2 };
    cout << s.candy(ratings) << endl;   
    system("pause");
    return 0;
}