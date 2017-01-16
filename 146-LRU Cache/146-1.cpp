#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, 
otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached
its capacity, it should invalidate the least recently used item before inserting a new item.
*/
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        auto iter = map.find(key);
        if (iter == map.end())
            return -1;
        use(key);
        return iter->second;
    }
    void set(int key, int value) {
        if (cap == 0) return;
        if (map.find(key) == map.end() && map.size() == cap) {
            map.erase(map.find(recentlyuse.front()));
            addr.erase(addr.find(recentlyuse.front()));
            recentlyuse.pop_front();
        }
        map[key] = value;
        use(key);
    }
private:
    void use(int key) {
        auto recentiter = addr.find(key);
        if (recentiter != addr.end())
            recentlyuse.erase(addr[key]);
        recentlyuse.push_back(key);
        addr[key] = --recentlyuse.end();
    }
    int cap;
    unordered_map<int, int> map;
    list<int> recentlyuse;
    unordered_map<int, list<int>::iterator> addr;
};
int main() {
    LRUCache L(2);
    return 0;
}
