题目：   
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```   
P   A   H   N    
A P L S I I G    
Y   I   R    
```
And then read line by line : "PAHNAPLSIIGYIR"    
Write the code that will take a string and make this conversion given a number of rows :     
string convert(string text, int nRows);       
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".       

1. 首先zigzag pattern指的是什么？     
```
0           2n-2
1        2n-3  2n-1
.     .           .           .
.  .                 .     .
n-1                     3n-3
```
上述形状字符串。      

2. 如果横向统计字符串，用的第一种方法是将横向的字符连接起来，像链表一样，从`k(n-1) (k>0)`向两个方向扩展，将`index-j`和`index+j`连接起来，然后根据索引生成横向排列字符。
```
0 -------->(2n-2)                      ->-1
1 ------>2n-3->2n-1                    ->-1
.     .           .           .        ->-1
.->.                 .     .           ->-1
(n-1)                 (3n-3)           ->-1
```
代码：    
```c++
//20 ms    Your runtime beats 52.60% of cppsubmissions
string convert(string s, int numRows) {
  if (numRows == 1)
    return s;
  int num = (s.size() - 1) / (numRows - 1);
  if (num == 0)
    return s;
  num = num*(numRows - 1);
  vector<int> index( s.size(),-1);
  for (int i = numRows-1; i < num; i+=numRows-1)
  {
    for (int j = 1; j < numRows; ++j)
      index[i - j] = i + j;
  }
  for (int i = num, j = 1; i + j < s.size(); ++j)
  {
    index[i - j] = i + j;
  }
  string ans;
  for (int i = 0; i < numRows&&i < s.size(); ++i)
  {
    int temp = i;
    do
    {
      ans.append(1,s[temp]);
      temp = index[temp];
    } while (temp!=-1);
  }
  return ans;
}
```
(1)首先考虑`numRows`为1的情况此时直接返回s       
(2)根据上面的`zigzag pattern`的规律，在转折处的`index`为`numRows`的倍数（0除外）,
而向两边扩展为了减少范围的比较，选择先选出可以直接两边扩展的转折点，`s.size()-1`即最末端的`index`     
(3)对于小于`numRows`长度的字符串直接返回     
(4)对于可以直接连接的字符，将其连接保存在`vector<int> index`中，`index[i - j] = i + j`       
(5)对于无法完全配对的，用字符串长度限制将剩余的连接       
(6)根据行数限制和最尾端下一个字符的下标记录（-1）生成所求的字符串       

3. 上面的实在是繁琐，而且不够直接后来想了下为什不不直接按照行的方式找，于是用了下面这种        
```c++
//16 ms   Your runtime beats 70.79% of cppsubmissions
string convert2(string s, int numRows){
  if (numRows == 1 || s.size() <= numRows)
    return s;
  string ans(s.size(),' ');
  int index = 0;
  for (int i = 0; i < numRows; ++i)
  {
    int temp = i;
    int incre = 2 * (numRows - 1) - i * 2;
    do
    {
      if (incre == 0)
        incre = 2 * (numRows - 1) - incre;
      ans[index++] = s[temp];
      temp += incre;
      incre = 2 * (numRows - 1) - incre;
    } while (temp<s.size());
  }
  return ans;
}
```
(1)首先要明确，`zigzag pattern`类似N子形，直线上两个对应点的`index`之差是不变的，均为`2n-2`         
(2)对于在第一行的点和最后一行的点他们之间的间隔为`2n-2`，而其他的两个点之间还隔了一个点，两个间隔的和为`2n-2`                      
(3)即间隔从``[2n-2],[2n-4,2],[2n-6,4]...`到`[2,2n-4],[2n-2]`，分别按照这个规律给各行找到相应的下一个字符          
(4)对于首尾两行的少一个点的情况（incre==0）直接跳过        
