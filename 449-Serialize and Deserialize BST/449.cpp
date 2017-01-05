#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
 or transmitted across a network connection link to be reconstructed later in the same or another computer environment. 
Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm
 should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original 
tree structure.
The encoded string should be as compact as possible. 
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless. 
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
