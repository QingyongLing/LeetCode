#include <iostream>
#include <vector>
#include <unordered_set>
#include <time.h>
using namespace std;
/*
Design a data structure that supports all following operations in average O(1) time.
1.insert(val): Inserts an item val to the set if not already present.
2.remove(val): Removes an item val from the set if present.
3.getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Example:
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();
// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);
// Returns false as 2 does not exist in the set.
randomSet.remove(2);
// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);
// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();
// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);
// 2 was already in the set, so return false.
randomSet.insert(2);
// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (set.find(val) == set.end()) {
            set.insert(val);
            vec.push_back(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (set.find(val) != set.end()) {
            set.erase(val);
            if (set.size() <= vec.size() / 2)
                vec = vector<int>(set.begin(), set.end());
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        //set must not be empty
        int s = vec.size();
        int r = rand() % s;
        while (set.find(vec[r]) == set.end()) {
            r = rand() % s;
        }
        return vec[r];
    }
private:
    unordered_set<int> set;
    vector<int> vec;
};
int main() {
    
    return 0;
}