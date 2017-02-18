#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W).
You also have several balls in your hand.
Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost 
place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this 
until no more balls can be removed.
Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls,
output -1.
Examples:
Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty
Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty
Note:
1.You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
2.The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
3.The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
4.Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.
*/

class Solution {
public:
    int findMinStep(string board, string hand) {
        //RYBGW-->01234
        if (board.empty())return 0;
        string str("RYBGW");
        int chartoint[26] = {}, count = 0;
        for (int i = 0; i < str.size(); ++i)
            chartoint[str[i] - 'A'] = i;
        vector<pair<int, int>> next;
        vector<int> inthand(str.size(), 0);
        for (int i = 0; i < board.size(); ++i) {
            if (i&&board[i] != board[i - 1])
                next.push_back(make_pair(chartoint[board[i - 1] - 'A'], count)), count = 0;
            ++count;
        }
        next.push_back(make_pair(chartoint[board.back() - 'A'], count));
        for (char c : hand)++inthand[chartoint[c - 'A']];
        int num = findimpl(next, inthand);
        return num == -1 ? num : hand.size() - num;
    }
private:
    int findimpl(vector<pair<int,int>> board,vector<int> &hand) {
        if (board.empty())
            return accumulate(hand.begin(), hand.end(), 0);
        int maxunuse = -1;
        for (int i = 0; i < board.size(); ++i) {
            if (3 - board[i].second > hand[board[i].first])
                continue;
            int sub = 3 - board[i].second;
            if (board[i].second > 2)sub = 0;
            hand[board[i].first] -= sub;
            vector<pair<int, int>> next(board.begin(), board.begin() + i);
            if (i < board.size() - 1) {
                if (i != 0 && board[i + 1].first == next.back().first) {
                    next.back().second += board[i + 1].second;
                    next.insert(next.end(), board.begin() + i + 2, board.end());
                }
                else
                    next.insert(next.end(), board.begin() + i + 1, board.end());
            }
            int num = findimpl(next, hand);
            maxunuse = max(num, maxunuse);
            hand[board[i].first] += sub;
        }
        return maxunuse;
    }
};
int main() {
    Solution s;
    cout << s.findMinStep("RBYYBBRRB", "YRBGB") << endl;
    return 0;
}
