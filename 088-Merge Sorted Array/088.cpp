#include <iostream>
#include <vector>
using namespace std;
/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n;   
        --m, --n;
        while (--index >= 0)
        {
            if (m >= 0 && n >= 0)
            {
                if (nums1[m] > nums2[n])
                    nums1[index] = nums1[m--];
                else
                    nums1[index] = nums2[n--];
            }
            else if (m >= 0 && n < 0)
            {
                nums1[index] = nums1[m--];
            }
            else
                nums1[index] = nums2[n--];
        }
    }
};
int main()
{  
    Solution s;
    vector<int> vec1 = { 1,3,6,8,9 }, vec2 = { 2,3,5,7,8,10,23 };
    vec1.resize(vec1.size() + vec2.size());
    s.merge(vec1, 5, vec2, vec2.size());
    for (auto &c : vec1)
        cout << c << " ";
    system("pause");
    return 0;
}
