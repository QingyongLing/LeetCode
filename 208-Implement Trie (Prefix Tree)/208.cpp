#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        str = false;
        for (auto &p : arr)p = nullptr;
    }
    ~TrieNode() {
        for (auto &p : arr)
            if (p) delete p;
    }
    bool str;
    TrieNode *arr[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            int c = word[i] - 'a';
            if (temp->arr[c])
                temp = temp->arr[c];
            else
                temp = temp->arr[c] = new TrieNode();
        }
        temp->str = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            int c = word[i] - 'a';
            temp = temp->arr[c];
            if (temp == nullptr)
                return false;
        }
        return temp->str;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int c = prefix[i] - 'a';
            temp = temp->arr[c];
            if (temp == nullptr)
                return false;
        }
        return true;
    }
    ~Trie() {
        delete root;
    }
private:
    TrieNode* root;
};
int main() {
    Trie t;
    t.insert("abcdfff");
    return 0;
}
