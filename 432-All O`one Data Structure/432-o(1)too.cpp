#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <time.h>
#include <stack>
using namespace std;
/*
Implement a data structure supporting the following operations:
1.Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by 1.Key is guaranteed to be 
a non-empty string.
2.Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key
by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
3.GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
4.GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.
*/
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto iter = strs.find(key);
        if (iter == strs.end()) {
            strs[key] = 1;
            auto tempiter = count.find(1);
            if (tempiter == count.end()) {
                countset.push_front(unordered_set<string>());
                count.insert(make_pair(1, countset.begin()));
                count[1]->insert(key);
            }
            else {
                tempiter->second->insert(key);
            }
        }
        else {
            int &num = strs[key];
            auto mapiter = count.find(num);
            auto setiter = mapiter->second;
            auto next = count.find(++num);
            if (next == count.end()) {
                //优化下
                if (setiter->size() == 1) {
                    count.erase(mapiter);
                    count.insert(make_pair(num, setiter));
                    return;
                }
                if (setiter == --countset.end()) {
                    countset.push_back(unordered_set<string>());
                    count.insert(make_pair(num, --countset.end()));
                    count[num]->insert(key);
                }
                else {
                    auto temp = setiter;
                    auto incplace = countset.insert(++temp, unordered_set<string>());
                    incplace->insert(key);
                    count.insert(make_pair(num, incplace));
                }
            }
            else {
                next->second->insert(key);
            }
            setiter->erase(setiter->find(key));
            if (setiter->empty()) {
                countset.erase(setiter);
                count.erase(mapiter);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto iter = strs.find(key);
        if (iter == strs.end()) return;
        int &num = iter->second;
        auto mapiter = count.find(num);
        auto setiter = mapiter->second;
        if (num != 1) {
            auto tempiter = count.find(--num);
            if (tempiter == count.end()) {
                //优化下
                if (setiter->size() == 1) {
                    count.erase(mapiter);
                    count.insert(make_pair(num, setiter));
                    return;
                }
                auto decplace = countset.insert(setiter, unordered_set<string>());
                decplace->insert(key);
                count.insert(make_pair(num, decplace));
            }
            else {
                tempiter->second->insert(key);
            }
        }
        else {
            strs.erase(iter);
        }
        setiter->erase(setiter->find(key));
        if (setiter->empty()) {
            countset.erase(setiter);
            count.erase(mapiter);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (countset.empty()) return string("");
        else return *countset.back().begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (countset.empty()) return string("");
        else return *countset.front().begin();
    }
private:
    unordered_map<string, int> strs;
    unordered_map<int, list<unordered_set<string>>::iterator> count;
    list<unordered_set<string>> countset;
};

int main() {
    AllOne all;
    cout <<  endl;
}