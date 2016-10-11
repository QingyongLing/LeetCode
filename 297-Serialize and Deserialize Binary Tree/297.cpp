#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
For example, you may serialize the following tree
   1
  / \
 2   3
    / \
   4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.
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
        string result;
        if (root == NULL) return result;
        deque<TreeNode*> deq;
        deq.push_back(root);
        while (!deq.empty()) {
            int num = deq.size();
            while (num--) {
                auto &cur = deq.front();
                if (cur != NULL) {
                    result.append(to_string(cur->val));
                    deq.push_back(cur->left);
                    deq.push_back(cur->right);
                }
                else
                    result.append("null");
                result.push_back(',');
                deq.pop_front();
            }          
        }
        return result;
    }

    // Decodes your encoded data to tree.
    //first -> index  second -> 
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        int index = 0, num = data.find(',');
        deque<TreeNode*> deq;
        int rootnum = stoi(data.substr(0, num));
        TreeNode* root = new TreeNode(rootnum);
        deq.push_back(root);
        index = num + 1;
        bool leftson = true;
        while (index < data.size()) {
            int next = data.find(',', index);
            if (data[index] != 'n') {
                int sonnum = stoi(data.substr(index, next - index));
                TreeNode* son = new TreeNode(sonnum);
                if (leftson) 
                    deq.front()->left = son;
                else
                    deq.front()->right = son; 
                deq.push_back(son);
            }
            index = next + 1;
            leftson = !leftson;
            if (leftson) deq.pop_front();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main() {
    Codec C;
    TreeNode node1(1),node2(2),node3(3);
    node1.left = &node2;
    node2.right = &node3;
    cout << C.serialize(&node1) << endl;
    return 0;
}