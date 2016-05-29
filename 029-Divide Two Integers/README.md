1. 溢出    
```cpp
if (abs(divisor) == 1)
    return divisor > 0 ? dividend : (dividend == -1 - INT_MAX ? INT_MAX : -dividend);
```
如果dividend为-2147483648，divisor为-1那么导致溢出，要返回2147483647（INT_MAX）。

2. 转换     
在将负数转化为正数时，INT_MIN不能直接转换，所以要先类型提升以后再转换     
```cpp
long long absdividend = dividend;
long long absdivisor = divisor;
absdividend = abs(absdividend);
absdivisor = abs(absdivisor);
```

3. 采用二分查找，找到最大的n，满足`dividend<=divisor*2^n`。     
```cpp
auto binary_search_ = [&data](int num)->int
        {
            int left = 0, right = data.size() - 1, mid = 0;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (data[mid] <= num)
                {
                    if (data[mid + 1] > num)
                        break;
                    left = mid;
                    continue;
                }
                else
                {
                    right = mid;
                    continue;
                }
            }
            return mid;
        };
```
