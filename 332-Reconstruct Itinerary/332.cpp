#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus,
the itinerary must begin with JFK.
Note:
1.If there are multiple valid itineraries, you should return the itinerary that has the smallest 
lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller 
lexical order than ["JFK", "LGB"].
2.All airports are represented by three capital letters (IATA code).
3.You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, vector<pair<string, bool>>> map;
        for (auto &pa : tickets)
            map[pa.first].push_back(make_pair(pa.second, false));
        auto comp = [](pair<string, bool> &a, pair<string, bool> &b) { return a.first < b.first; };
        for (auto &m : map)
            sort(m.second.begin(), m.second.end(), comp);
        vector<string> result;
        string start("JFK");
        result.push_back(start);
        dfs(result, map, start, tickets.size() + 1);
        return result;
    }
    void dfs(vector<string>& result, unordered_map<string, vector<pair<string, bool>>>& map,string &next, int maxnum) {
        vector<pair<string, bool>> &nextstation = map[next];
        for (int i = 0; i < nextstation.size(); ++i) {
            if (nextstation[i].second == false) {
                result.push_back(nextstation[i].first);
                nextstation[i].second = true;
                dfs(result, map, nextstation[i].first, maxnum);
                if (maxnum == result.size())
                    return;
                result.pop_back();
                nextstation[i].second = false;
            }
        }
    }
};
int main() {
    Solution s;
    //[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    vector<pair<string, string>> vec = { { "JFK","SFO" }, { "JFK","ATL" },
    { "SFO","ATL" },{ "ATL","JFK"},{ "ATL","SFO" } };
    auto result = s.findItinerary(vec);
    for (auto &str : result)
        cout << str << " ";
    return 0;
}