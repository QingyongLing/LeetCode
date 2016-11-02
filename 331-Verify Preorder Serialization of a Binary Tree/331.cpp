#include <iostream>
#include <string>
using namespace std;
/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null 
node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
      _9_
     /   \
    3     2
   / \   / \
  4   1  #  6
 / \ / \   / \
 # # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#",
where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal serialization 
of a binary tree. Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two consecutive 
commas such as "1,,3".
Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true
Example 2:
"1,#"
Return false
Example 3:
"9,#,#,1"
Return false
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int index = 0;
        return valid(preorder, index) && (index >= preorder.size());
    }
    bool valid(string &str, int &index) {
        if (index >= str.size()) 
            return false;
        if (str[index] == '#') {
            index += 2;
            return true;
        }    
        else {
            while (index < str.size() && str[index++] != ',');
            if (valid(str, index) && valid(str, index))
                return true;
            else
                return false;
        }
    }
};
int main() {
    Solution s;
    string str("9,#,#,1");
    cout << s.isValidSerialization(str) << endl;
    return 0;
}