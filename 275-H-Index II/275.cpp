#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
Hint:
1.Expected runtime complexity is in O(log n) and the input is sorted.
Subscribe to see which companies asked this question
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int lo = 0, hi = citations.size() - 1, mid = 0;
        while (lo < hi - 1) {
            mid = (hi - lo) / 2 + lo;
            if (citations[mid] > citations.size() - mid)
                hi = mid;
            else if (citations[mid] < citations.size() - mid)
                lo = mid;
            else return citations[mid];
        }
        if (citations[lo] >= citations.size() - lo)
            return citations.size() - lo;
        else if (citations[hi] >= citations.size() - hi)
            return citations.size() - hi;
        return 0;
    }
};
int main() {    
    Solution s;
    vector<int> vec = { 0,1,1,5,6 };
    cout << s.hIndex(vec) << endl;
    system("pause");
    return 0;
}