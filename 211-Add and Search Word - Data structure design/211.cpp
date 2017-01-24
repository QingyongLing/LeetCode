#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters 
a-z or .. A . means it can represent any one letter.
For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
click to show hint.
You should be familiar with how a Trie works. If not, please work on this problem: Implement 
Trie (Prefix Tree) first.
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (root == nullptr)return false;
        return searchimpl(word, 0, root);
    }
    ~WordDictionary(){
        delete root;
    }
private:
    TrieNode* root;
    bool searchimpl(string &str, size_t index, TrieNode* root){
        if (index == str.size()) return false;
        char c = str[index];
        if (c == '.'){
            for (int i = 0; i < 26; ++i){
                if (root->arr[i]){
                    if (index == str.size() - 1 && root->arr[i]->str) return true;
                    if (searchimpl(str, 1 + index, root->arr[i])) return true;
                }
            }
        }
        else{
            if (root->arr[c - 'a']){
                if (index == str.size() - 1 && root->arr[c - 'a']->str) return true;
                else return searchimpl(str, 1 + index, root->arr[c - 'a']);
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}