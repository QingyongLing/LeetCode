#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
click to show more hints.
Hints: 1.This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
2.Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
3.Topological sort could also be done via BFS.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> map(numCourses);
        for (auto &edge : prerequisites)
            map[edge.second].push_back(edge.first);
        vector<bool> flag(numCourses, false), path(numCourses, false);
        bool cycle = false;
        for (int i = 0; i < numCourses;++i) {
            if (!flag[i])
                dfs(map, flag, path, cycle, i);
        }
        return !cycle;
    }
private:
    void dfs(vector<vector<int>> &map, vector<bool> &flag, vector<bool> &path, bool &cycle,int i) {
        flag[i] = true;
        path[i] = true;
        for (auto &num : map[i]) {
            if (path[num]){
                cycle = true;
                break;
            }
            if (!flag[num])
                dfs(map, flag, path, cycle, num);
        }
        path[i] = false;
    }
};
int main() {
    Solution s; 
    int num = 2;
    vector<pair<int, int>> vec = { {1,0},{0,1} };
    cout << (s.canFinish(num, vec) ? "true" : "false") << endl;
    system("pause");
    return 0;
}