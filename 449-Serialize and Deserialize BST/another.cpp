#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice
and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does 
not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        deque<TreeNode*> de;
        de.push_back(root);
        string str;
        while (!de.empty()) {
            TreeNode* temp = de.front();
            de.pop_front();
            if (temp) {
                str.append(to_string(temp->val));
                str.push_back(',');
                de.push_back(temp->left);
                de.push_back(temp->right);
            }
            else str.append("NULL,");
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == 'N') return NULL;
        size_t index = data.find(',');
        deque<TreeNode*> de;
        int num = stoi(data.substr(0, index));
        TreeNode* root = new TreeNode(num);
        de.push_back(root);
        while (1) {
            if (++index == data.size()) break;
            size_t temp = data.find(',', index);
            if (data[index] != 'N') {
                TreeNode* node = new TreeNode(stoi(data.substr(index, temp - index)));
                de.push_back(node);
                de.front()->left = node;
            }
            index = temp + 1;
            //if (index == data.size()) break;
            temp = data.find(',', index);
            if (data[index] != 'N') {
                TreeNode* node = new TreeNode(stoi(data.substr(index, temp - index)));
                de.push_back(node);
                de.front()->right = node;
            }
            index = temp;
            de.pop_front();
        }
        return root;
    }
};
int main() {
    Codec c;
    cout<<c.serialize(c.deserialize("1,2,NULL,NULL,NULL,"));
}
