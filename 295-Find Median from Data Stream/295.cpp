#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
Examples:
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Design a data structure that supports the following two operations:
•void addNum(int num) - Add a integer number from the data stream to the data structure.
•double findMedian() - Return the median of all elements so far.
For example:
add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.
*/
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (smaller.size() == bigger.size()) {
            if (smaller.empty()) 
                smaller.push_back(num);
            else {
                int smtop = bigger.front();
                if (num <= smtop) {
                    smaller.push_back(num);
                    push_heap(smaller.begin(), smaller.end());
                }
                else {
                    pop_heap(bigger.begin(), bigger.end(), greater<int>());
                    int temp = bigger.back();
                    bigger.pop_back();
                    smaller.push_back(temp);
                    push_heap(smaller.begin(), smaller.end());
                    bigger.push_back(num);
                    push_heap(bigger.begin(), bigger.end(), greater<int>());
                }
            }
        }
        else {
            int smtop = smaller.front();
            if (num >= smtop) {
                bigger.push_back(num);
                push_heap(bigger.begin(), bigger.end(), greater<int>());
            }
            else {
                pop_heap(smaller.begin(), smaller.end());
                int temp = smaller.back();
                smaller.pop_back();
                bigger.push_back(temp);
                push_heap(bigger.begin(), bigger.end(), greater<int>());
                smaller.push_back(num);
                push_heap(smaller.begin(), smaller.end());
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (smaller.size() == bigger.size())
            return (smaller.front() + bigger.front()) / 2.0;
        else
            return smaller.front();
    }
private:
    vector<int> smaller, bigger;
};

int main() {
    MedianFinder M;
    vector<int> vec = { 40,12,16,14,35,19,34,35,28,35,26 };
    for (auto v : vec) {
        M.addNum(v);
        cout << M.findMedian() << " ";
    }
    system("pause");
    return 0;
}