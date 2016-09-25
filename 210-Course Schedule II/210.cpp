#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
click to show more hints.
Hints: 1.This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
2.Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
3.Topological sort could also be done via BFS.
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> map(numCourses);
        for (auto &edge : prerequisites)
            map[edge.second].push_back(edge.first);
        vector<bool> flag(numCourses, false), path(numCourses, false);
        vector<int> order;
        bool cycle = false;
        for (int i = 0; i < numCourses;++i) {
            if (!flag[i])
                dfs(map, flag, path, cycle, i,order);
        }
        if (cycle)
            return vector<int>();
        else {
            reverse(order.begin(), order.end());
            return order;
        }
    }
private:
    void dfs(vector<vector<int>> &map, vector<bool> &flag, vector<bool> &path, bool &cycle,int i, vector<int> &order) {
        flag[i] = true;
        path[i] = true;
        for (auto &num : map[i]) {
            if (path[num]){
                cycle = true;
                break;
            }
            if (!flag[num])
                dfs(map, flag, path, cycle, num, order);
        }
        order.push_back(i);
        path[i] = false;
    }
};
int main() {
    Solution s; 
    int num = 4;
    vector<pair<int, int>> vec = { {1,0},{2,0},{3,1},{3,2} };
    auto result = s.findOrder(num, vec);
    for (auto n : result)
        cout << n << " ";
    cout << endl;
    system("pause");
    return 0;
}