### 求N位的格雷码，数字形式
##### 先举个例子，假设N为3，那么一种可能的格雷码为：
```cpp
0 0 0
0 0 1
0 1 1
0 1 0
1 1 0
1 1 1
1 0 1
1 0 0
```
可以发现0和1的顺序是交替变化的，在最高位只有顺序的形式，即先0后1，第二位出现了先0后1，再1再0的情形，第三位出现了先0后1再1再0的情况，并且重复出现了，我们可以用一个标志来表明正序和逆序，即01和10的情况，假设每次到下一位（除最高位）都分成true和false两种情况，那么true对应正序，false对应逆序，正序先添加0，后添加1，逆序先添加0后添加1，但是到下一位的时候统一保持先true再false的顺序。这样就可以满足上述格雷码的规律。
代码如下：
```cpp
vector<int> grayCode(int n) {
   vector<int> result;
   if (n == 0)
       return result;
   backtracking(result, n, true, 0);
   return result;
}
void backtracking(vector<int>& result, int k,bool f, int num)
{
   if (k == 0)
       result.push_back(num);
   else
   {
       int temp;
       temp = (1 << (k - 1));
       if (f)
       {
           backtracking(result, k - 1, f, num);
           backtracking(result, k - 1, !f, num | temp);
       }
       else
       {
           backtracking(result, k - 1, !f, num | temp);
           backtracking(result, k - 1, f, num);
       }
   }
}
```