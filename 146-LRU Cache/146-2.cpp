#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, 
otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached
its capacity, it should invalidate the least recently used item before inserting a new item.
*/
class Node {
public:
    int val;
    Node* pre, *next;
    Node(int v) :val(v), pre(nullptr), next(nullptr) {}
};
class List {
public:
    List() :head(0) {
        head.next = &head;
        head.pre = &head;
    }
    void pop_front() {
        Node *p = head.next;
        head.next = p->next;
        head.next->pre = &head;
        delete p;
    }
    int front() {
        return head.next->val;
    }
    int back() {
        return head.pre->val;
    }
    Node* push_back(int val) {
        Node *n(new Node(val));
        linkback(n);
        return n;
    }
    void toback(Node* node) {
        Node* p = node->pre;
        p->next = node->next;
        node->next->pre = p;
        linkback(node);
    }
    ~List() {
        while (head.next != &head)
            pop_front();
    }
private:
    void linkback(Node *n) {
        head.pre->next = n;
        n->next = &head;
        n->pre = head.pre;
        head.pre = n;
    }
    Node head;
};
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
        if (recentiter != addr.end()) {
            if (recentlyuse.back() != key)
                recentlyuse.toback(recentiter->second);
            return;
        }
        addr[key] = recentlyuse.push_back(key);
    }
    int cap;
    unordered_map<int, int> map;
    List recentlyuse;
    unordered_map<int, Node*> addr;
};
int main() {
    LRUCache L(2);
    L.set(1, 2);
    L.set(2, 3);
    L.set(3, 4);
    cout << L.get(1) << L.get(2) << L.get(3) << endl;
    return 0;
}
