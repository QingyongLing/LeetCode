//Determine whether an integer is a palindrome. Do this without extra space.
//click to show spoilers.
//Some hints:
//Could negative integers be palindromes? (ie, -1)
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
//There is a more generic way of solving this problem.
//
#include <assert.h>
class Solution2
{
public:
    //Runtime: 76 ms
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int num = 1;
        while (x / num >= 10)
            num *= 10;
        while (x)
        {
            int left = x / num;
            int right = x % 10;
            if (left != right)
                return false;
            x -= num*left;
            num /= 100;
            x /= 10;
        }
        return true;
    }
};

int main()
{

    Solution2 s;
    assert(s.isPalindrome(121));
    assert(s.isPalindrome(1));
    assert(!s.isPalindrome(-1));
    assert(!s.isPalindrome(-121));
    assert(s.isPalindrome(11));
    return 0;
}
