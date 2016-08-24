### 重复序列的所有子集
对与这个问题，重复的元素带来了顺序上的不确定性，为此我们要明确的是重复元素加入的个数，每种情况相当于一个值。
假设重复的元素为A1，A2，A3...An，那么添加元素的情况为：
```
A1，A2,A3...An
A2,A3...An
...
An
(不添加任何该值)
```
以上这几种情况涵盖了包含A值的所有情况。实现方式则考虑如果已经选择了某个A元素，那么接下来必须把后面的A元素全部添加。可以把第一次选择A元素的下标后移。实现代码为：
```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty())
        return result;
    sort(nums.begin(), nums.end());
    vector<int> sub;
    backtracking(result, nums, sub, 0);
    return result;
}
void backtracking(vector<vector<int>> &result, vector<int>& nums, vector<int>& sub,int n){
    if (n == nums.size())
        result.push_back(sub);
    else {   
         sub.push_back(nums[n]);
         backtracking(result, nums, sub, n + 1);
         sub.pop_back();
         if (sub.empty() || !sub.empty() && sub.back() != nums[n])
             backtracking(result, nums, sub, n + 1);                        
    }
}
```
注：把添加放在比不添加前面可提高4ms（leetcode）