#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.
For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string>::iterator iter = words.begin();      
        while (iter != words.end())
        {
            int len=0;
            vector<string*> tempstrs;           
            tempstrs.push_back(&*iter);
            len += (*iter).size();
            ++iter;
            while (iter<words.end()&&len + 1 + iter->size() <= maxWidth)
            {
                tempstrs.push_back(&*iter);
                len += 1 + iter->size();
                ++iter;
            }
            int spacenum = maxWidth - len + tempstrs.size() - 1;
            if (tempstrs.size() == 1)
            {
                string str = *tempstrs[0];
                str.append(string(spacenum, ' '));
                result.push_back(str);
            }
            else
            {
                int insertplace = tempstrs.size() - 1;
                int temp = 0, spaceleft = 0;
                //最后一行左对齐，单词间隔为1个空格
                if (iter == words.end())
                {
                    temp = 1;
                    spaceleft = 0;
                }
                else
                {
                    temp= spacenum / insertplace;
                    spaceleft = spacenum - temp*insertplace;
                }
                string str;
                for (int i = 0; i < insertplace; ++i)
                {
                    str.append(*tempstrs[i]);
                    int another = i < spaceleft ? 1 : 0;
                    str.append(string(temp + another, ' '));
                }
                str.append(*tempstrs[insertplace]);
                if (iter == words.end())
                    str.append(string(maxWidth - len, ' '));
                result.push_back(str);
            }         
        }
        return result;
    }
};
int main()
{    
    Solution s;  
    vector<string> vec = { "This", "is", "an", "example", "of", "text", "justification." };
    auto result = s.fullJustify(vec, 16);
    for (auto &c : result)
    {
        cout << c << "|" << endl;
    }
    system("pause");
}
