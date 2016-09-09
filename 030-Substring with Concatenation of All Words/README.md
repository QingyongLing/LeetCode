1. 貌似字符串直接比较比较耗时，于是用STL里的hash先做了哈希    
```cpp
for (int i = 0; i <= s.size() - subsize; ++i)
{
    hash_table_s.push_back(str_hash(s.substr(i, subsize)));
}
for (int i = 0; i < words.size(); ++i)
{
    ++hash_table_words[str_hash(words[i])];
}
```

2. 第一次ac的结果不是很理想，300ms+，比Py还慢，Orz     
一开始的时候是一次一次在比对，后来觉得代码不好看，改成了把数据一抓然后排序去比，实际上复杂度差不多
```cpp
        for (int i = 0; i <= ssize;)
        {
            if (findwords(hash_table_s, i, subsize, hash_table_words,words.size()))
            {
                result.push_back(i);               
            }
            ++i;
        }
```
`findwords`就一个功能判断以此为起点的序列是否满足要求，不过按照集合和次数统计去比较略觉麻烦，改了一下
```cpp
        vector<size_t> hash_table_s, hash_table_words;
        int ssize = s.size() - words.size()*subsize;
        for (int i = 0; i <= s.size() - subsize; ++i)
        {
            hash_table_s.push_back(str_hash(s.substr(i, subsize)));
        }
        for (int i = 0; i < words.size(); ++i)
        {
            hash_table_words.push_back(str_hash(words[i]));
        }
        sort(hash_table_words.begin(), hash_table_words.end());
        vector<size_t> temphash(hash_table_words.size(), 0);
        for (int i = 0; i <= ssize;++i)
        {           
            if (binary_search(hash_table_words.begin(), hash_table_words.end(), hash_table_s[i]))
            {
                for (int j = 0; j < words.size(); ++j)
                {
                    temphash[j] = hash_table_s[i + j*subsize];
                }
                sort(temphash.begin(), temphash.end());
                if (temphash == hash_table_words)
                    result.push_back(i);
            }
        }
```
改成直接在`vector`里比较，省了好多麻烦    

3.然而一开始做的效率并不高，提示里表示要采用`Two Poniters`，Orz，于是再改     
```cpp      
        vector<size_t> hash_table_s;
        map<size_t, int> hash_table_words;
        for (int i = 0; i <= s.size() - subsize; ++i)
        {
            hash_table_s.push_back(str_hash(s.substr(i, subsize)));
        }
        for (int i = 0; i < words.size(); ++i)
        {
            ++hash_table_words[str_hash(words[i])];
        }       
        for (int i = 0; i < subsize; ++i)
        {
            int left = i, count = 0;
            map<size_t, int> legal;
            for (int j = i; j < hash_table_s.size(); j += subsize)
            {
                if (count < words.size())
                {
                    auto iter = hash_table_words.find(hash_table_s[j]);
                    if (iter == hash_table_words.end())
                    {
                        count = 0;
                        legal.clear();
                        left = j + subsize;
                    }
                    else
                    {
                        ++count;
                        int num = ++legal[iter->first];
                        if (num > iter->second)
                        {
                            do
                            {
                                --count;
                                --legal[hash_table_s[left]];
                                left += subsize;
                            } while (hash_table_s[left - subsize] != iter->first);
                        }
                        if (count == words.size())
                        {
                            result.push_back(left);
                            --count;
                            --legal[hash_table_s[left]];
                            left += subsize;
                        }
                    }
                }                
            }
        }
        return result;
```
首先分类，按照每个`word`的长度相当于分成了多个链表，也就是：
[0,subsize-1]->[subsize,2*subsize-1]->.....       
[1,subsize]->[subsize+1,2*subsize]->.....       
[2,subsize+1]->[subsize+2,2*subsize+1]->.....       
....
[subsize-1,2*subsize-2]->[2*subsize-1,3*subsize-2]->.....       
把这几个链表都遍历一遍
```cpp
int left = i, count = 0;
map<size_t, int> legal;
```
两个指针中左指针为left，右指针为j，往右边移动，count为满足条件的数目，legal用来统计次数，left是符合条件的起始点，j是遍历的经过点，count是满足的总数，legal代表每个子字符串符合的个数      
```cpp
auto iter = hash_table_words.find(hash_table_s[j]);
if (iter == hash_table_words.end())
{
    count = 0;
    legal.clear();
    left = j + subsize;
}
```
当j遇到不符合条件的情况直接移动到下一个，作为左指针起点      
```cpp
++count;
int num = ++legal[iter->first];
if (num > iter->second)
{
    do
    {
        --count;
        --legal[hash_table_s[left]];
        left += subsize;
    } while (hash_table_s[left - subsize] != iter->first);
}
if (count == words.size())
{
    result.push_back(left);
    --count;
    --legal[hash_table_s[left]];
    left += subsize;
}
```
满足条件时，比较是否超出子字符串的次数限制，一旦超出，把左指针右移，直到该字符串的计数减1，也就是抛弃了原来left到第一个该字符串的那一部分        
判断count是否符合要求，如果符合要求，左指针右移一个位置（右指针一直在右移），再减去刚刚原来那个left的计数值          
