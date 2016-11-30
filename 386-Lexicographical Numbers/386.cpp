#include <iostream>
#include <vector>
using namespace std;
/*
Given an integer n, return 1 - n in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

/*
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int result[n];
        int index = 0;
        addnum(1, result, index, n);
        return vector<int>(result, result + n);
    }
private:
    void addnum(int start, int *result, int &index, int maxn) {
        for (int i = 0; i < 10; ++i) {
            int temp = start + i;
            if (temp <= maxn) {
                if (i == 9 && temp % 10 == 0) continue;
                result[index++] = temp;
                if (temp * 10 <= maxn)
                    addnum(temp * 10, result, index, maxn);
            }
        }
    }
};
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        addnum(1, result, n);
        return result;
    }
private:
    void addnum(int start, vector<int> &result, int maxn) {
        for (int i = 0; i < 10; ++i) {
            int temp = start + i;
            if (temp <= maxn) {
                if (i == 9 && temp % 10 == 0) continue;
                result.push_back(temp);
                if (temp * 10 <= maxn)
                    addnum(temp * 10, result, maxn);
            }
        }
    }
};

int main() {
    Solution s;
    auto vec = s.lexicalOrder(150);
    for (int i : vec)
        cout << i << endl;
    return 0;
}