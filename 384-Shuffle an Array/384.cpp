#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
/*
Shuffle a set of numbers without duplicates.
Example:
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);
// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();
// Resets the array back to its original configuration [1,2,3].
solution.reset();
// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
public:
    Solution(vector<int> nums) {
        num = nums;
        suff = nums;
        srand(time(NULL));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return num;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {

        if (!suff.empty()) {
            int n1 = rand() % suff.size();
            int n2 = rand() % suff.size();
            swap(suff[n1], suff[n2]);
        }
        return suff;
    }
private:
    vector<int> num;
    vector<int> suff;
};


int main() {
    return 0;
}