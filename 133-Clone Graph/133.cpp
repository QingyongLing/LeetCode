#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;
/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.
1.First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
2.Second node is labeled as 1. Connect node 1 to node 2.
3.Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
   1
  / \
 /   \
0 --- 2
     / \
     \_/
*/
class Solution {
public:
    struct UndirectedGraphNode {
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : label(x) {};        
    };
    //dfs
    unordered_map<int, UndirectedGraphNode *> map;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        auto iter = map.find(node->label);
        if (iter != map.end()) return iter->second;
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        map.insert(make_pair(node->label, newnode));
        for (auto neighbor : node->neighbors) {
            newnode->neighbors.push_back(cloneGraph(neighbor));
        }
        return newnode;
    }
    //bfs
    UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        deque<UndirectedGraphNode *> NeighborNode;
        unordered_map<int, UndirectedGraphNode *> map;
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        NeighborNode.push_back(node);
        map.insert(make_pair(node->label, newnode));
        while (!NeighborNode.empty()) {
            UndirectedGraphNode *CurrentNode = NeighborNode.front();
            NeighborNode.pop_front();
            for (auto neighbor : CurrentNode->neighbors) {
                auto iter = map.find(neighbor->label);
                if (iter == map.end()) {
                    NeighborNode.push_back(neighbor);
                    map.insert(make_pair(neighbor->label, new UndirectedGraphNode(neighbor->label)));
                }
                map[CurrentNode->label]->neighbors.push_back(map[neighbor->label]);           
            }
        }

    }
};
int main() {
    Solution s;
    
    system("pause");
    return 0;
}