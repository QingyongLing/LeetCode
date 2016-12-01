#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Suppose we abstract our file system by a string in the following manner:
The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an 
empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing
a file file2.ext.
We are interested in finding the longest (number of characters) absolute path to a file within our file system. 
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and 
its length is 32 (not including the double quotes).
Given a string representing the file system in the above format, return the length of the longest absolute path 
to file in the abstracted file system. If there is no file in the system, return 0.
Note:
•The name of a file contains at least a . and an extension.
•The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.
Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
Subscribe to see which companies asked this question
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> len;
        int index = 0, num = 0, maxlen = 0;
        bool file = false;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '\n' || i == input.size() - 1) {
                if (file) {
                    int temp = 0;
                    for (int j = 0; j < num; ++j)
                        temp += len[j] + 1;
                    temp += i - index;
                    if (i == input.size() - 1) ++temp;
                    maxlen = max(maxlen, temp);
                    file = false;
                }
                else {
                    if (len.size() < num + 1)
                        len.push_back(i - index);
                    else {
                        len.resize(num);
                        len.push_back(i - index);
                    }       
                }
                num = 0;
                while (input[++i] == '\t')++num;
                //233333，orz
                if (input[i] == ' '&&num < len.size()) {
                    i += (len.size() - num) * 4;
                    num += len.size() - num;
                } 
                i -= 1;
                index = i + 1;
            }
            else if (input[i] == '.') {
                file = true;
            }
        }
        return maxlen;
    }
};

int main() {
    Solution s;
    //10
    cout << s.lengthLongestPath("a\n\tb\n\t\tc.txt\n\taaaa.txt")<<endl;
    return 0;
}