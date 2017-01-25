#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
For example,
Given words = ["oath","pea","eat","rain"] and board =
[
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
click to show hint.
You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What 
kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about 
a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie 
(Prefix Tree) first.
*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        index = -1;
        for (auto &p : arr)p = nullptr;
    }
    ~TrieNode() {
        for (auto &p : arr)
            if (p) delete p;
    }
    int index;
    TrieNode *arr[26];
};

class Solution {
public:
    Solution(){
        root = new TrieNode();
    }
    ~Solution(){
        delete root;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || words.empty())return result;
        for (int i = 0; i < words.size(); ++i)
            insertword(words[i], i);
        int row = board.size(), col = board[0].size();
        vector<vector<int>> flag(row, vector<int>(col));
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                TrieNode *p = root->arr[board[i][j] - 'a'];
                if (p) findwordsimpl(words, board, flag, i, j, p, result);
            }
        }
        return result;
    }
private:
    TrieNode* root;
    void insertword(string &word, int n){
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            int c = word[i] - 'a';
            if (temp->arr[c])
                temp = temp->arr[c];
            else
                temp = temp->arr[c] = new TrieNode();
        }
        temp->index = n;
    }
    void findwordsimpl(vector<string>& words, vector<vector<char>>& board, vector<vector<int>> &flag, int x, int y, TrieNode *root, vector<string> &result){
        if (root->index != -1){
            result.push_back(words[root->index]);
            root->index = -1;
        }
        flag[x][y] = 1;
        static int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < 4; ++i){
            int tempx = x + dx[i], tempy = y + dy[i];
            if (tempx < 0 || tempx >= row || tempy < 0 || tempy >= col || flag[tempx][tempy]) continue;
            int c = board[tempx][tempy] - 'a';
            if (root->arr[c])
                findwordsimpl(words, board, flag, tempx, tempy, root->arr[c], result);
        }
        flag[x][y] = 0;
    }
};
int main() {
    vector<vector<char>> vec = {
            { 'o', 'a', 'a', 'n' },
            { 'e', 't', 'a', 'e' },
            { 'i', 'h', 'k', 'r' },
            { 'i', 'f', 'l', 'v' }
    };
    vector<string> words = { "oath", "pea", "eat", "rain" };
    Solution s;
    for (auto &str : s.findWords(vec, words))
        cout << str << endl;
    return 0;
}