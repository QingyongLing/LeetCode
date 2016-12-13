#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        unordered_map<int, int> map;
        map[0] = 1;
        return pathsumimpl(map, root, sum, 0);
    }

    int pathSum2(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        vector<int> vec;
        int count = 0;
        pathsumimpl2(vec, root, sum, count);
        return count;
    }
private:
    int pathsumimpl(unordered_map<int, int>& map, TreeNode* root, int sum, int currentsum) {
        currentsum += root->val;
        int count = map[currentsum - sum];
        ++map[currentsum];
        if (root->left)
            count += pathsumimpl(map, root->left, sum, currentsum);
        if (root->right)
            count += pathsumimpl(map, root->right, sum, currentsum);
        --map[currentsum];
        return count;
    }

    void pathsumimpl2(vector<int> &vec, TreeNode* root, int sum,int &count) {
        vec.push_back(0);
        for (auto &i : vec) {
            i += root->val;
            if (i == sum)++count;
        }
        if (root->left != NULL)
            pathsumimpl2(vec, root->left, sum, count);
        if(root->right!=NULL)
            pathsumimpl2(vec, root->right, sum, count);
        for (auto &i : vec)
            i -= root->val;
        vec.pop_back();
    }
};
int main() {
    cout <<  endl;
}