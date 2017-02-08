#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
For a undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. Among all possible rooted trees, those with 
minimum height are called minimum height trees (MHTs). Given such a graph, write a 
function to find all the MHTs and return a list of their root labels.
Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the 
number n and a list of undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
[0, 1] is the same as [1, 0] and thus will not appear together in edges.
Example 1:
Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
  0
  |
  1
 / \
2   3
return  [1]
Example 2:
Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
0  1  2
 \ | /
   3
   |
   4
   |
   5
return  [3, 4]
Hint:
1.How many MHTs can a graph have at most?
Note:
(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
Subscribe to see which companies asked this question.
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> answer;
        if (n == 0)return answer;
        if (n == 1)return { 0 };
        map = vector<unordered_set<int>>(n);
        for (auto &edge : edges){
            map[edge.first].insert(edge.second);
            map[edge.second].insert(edge.first);
        }
        int maxlen = 0, node = 0, othernode = 0;
        flag = vector<int>(n, 0);
        farestnode(0, 0, maxlen, node);
        maxlen = 0;
        flag = vector<int>(n, 0);
        farestnode(node, 0, maxlen, othernode);
        vector<int> path;
        flag = vector<int>(n, 0);
        longestpath(path, node, othernode);
        if (path.size() % 2)
            answer.push_back(path[path.size() / 2]);
        else{
            answer.push_back(path[path.size() / 2]);
            answer.push_back(path[path.size() / 2 - 1]);
        }
        return answer;
    }
private:
    vector<unordered_set<int>> map;
    vector<int> flag;
    void farestnode(int curnode, int curlen, int &maxlen, int &node){
        flag[curnode] = 1;
        ++curlen;
        if (curlen > maxlen)
            maxlen = curlen, node = curnode;
        for (auto &n : map[curnode]){
            if (!flag[n])
                farestnode(n, curlen, maxlen, node);
        }
    }
    void longestpath(vector<int> &path, int curnode, int target){
        path.push_back(curnode);
        flag[curnode] = 1;
        for (auto &n : map[curnode]){       
            if (!flag[n])
                longestpath(path, n, target);
            if (!path.empty() && path.back() == target)
                return;
        }
        flag[curnode] = 0;
        path.pop_back();
    }
};
int main(){
    Solution s;
    vector<pair<int, int>> vec = { { 0, 3 }, { 1, 3 }, { 2, 3 }, { 4, 3 }, { 5, 4 } };
    for (auto i : s.findMinHeightTrees(6, vec))
        cout << i << "  ";
    return 0;
}