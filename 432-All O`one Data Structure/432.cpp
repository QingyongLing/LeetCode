#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
Implement a data structure supporting the following operations:
1.Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by 1. Key is guaranteed 
to be a non-empty string.
2.Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing 
key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
3.GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
4.GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.
*/
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        maxkeycount = 0;
        minkeycount = 0;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto iter = strs.find(key);
        if (iter == strs.end()) {
            strs.insert(make_pair(key, 1));
            count[1].insert(key);
            maxkeycount = max(maxkeycount, 1);
            minkeycount = 1;
        }
        else {
            int &num = iter->second;
            auto &countset = count[num];
            countset.erase(countset.find(key));
            if (count[minkeycount].empty())
                ++minkeycount;
            if (countset.empty())
                count.erase(count.find(num));
            ++num;
            count[num].insert(key);
            maxkeycount = max(maxkeycount, num);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto iter = strs.find(key);
        if (iter == strs.end()) return;
        int &num = iter->second;
        auto &countset = count[num];
        countset.erase(countset.find(key));
        if (countset.empty())
            count.erase(count.find(num));
        if (count[maxkeycount].empty())
            --maxkeycount;
        if (num == 1) {
            strs.erase(iter);
            if (count.find(minkeycount) == count.end()) {
                minkeycount = maxkeycount;
                for (auto &p : count) {
                    minkeycount = min(minkeycount, p.first);
                }
            }
        }
        else {
            --num;
            count[num].insert(key);
            if (num<minkeycount) minkeycount = num;
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        auto iter = count.find(maxkeycount);
        if (iter != count.end() && !iter->second.empty())
            return *(iter->second.begin());
        else
            return string("");
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        auto iter = count.find(minkeycount);
        if (iter != count.end() && !iter->second.empty())
            return *(iter->second.begin());
        else
            return string("");
    }
private:
    int maxkeycount;
    int minkeycount;
    unordered_map<int, unordered_set<string>> count;
    unordered_map<string, int> strs;
};

int main() {
    
    cout <<  endl;
}