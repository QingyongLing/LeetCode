#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
You need to construct a binary tree from a string consisting of parenthesis and integers.
The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis.
The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
You always start to construct the left child node of the parent first if it exists.
Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:
     4
   /   \
  2     6
 / \   /
3   1 5
Note:
1.There will only be '(', ')', '-' and '0' ~ '9' in the input string.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty())return NULL;
        if (s.find('(') == s.npos)
            return new TreeNode(stoi(s));
        return construct(s, 0, s.size() - 1);
    }
private:
    TreeNode* construct(string &s, size_t left, size_t right) {
        if (left > right)return NULL;
        int next = left;
        while (s[next] != '('&&next < right + 1)++next;
        int num = stoi(s.substr(left, next - left));
        left = next;
        int countl = 1;
        while (countl&&next < right + 1) {
            ++next;
            if (s[next] == ')')--countl;
            else if (s[next] == '(')++countl;
        }
        TreeNode* p = new TreeNode(num);
        p->left = construct(s, left + 1, next - 1);
        p->right = construct(s, next + 2, right - 1);
        return p;
    }
};

int main() {
    Solution s;
    return 0;
}