英文链接: https://leetcode.com/problems/valid-palindrome/  
中文链接: https://leetcode-cn.com/problems/valid-palindrome/

ASCII码  
65: A  
97: a

```
class Solution {
public:
    bool isPalindrome(string s) {
        bool isPalindrome = true;
        if (s.empty())
        {
            return isPalindrome;
        }

        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (!isAlphaNum(s[left]))
            {
                ++left;
            }
            else if (!isAlphaNum(s[right]))
            {
                --right;
            }
            // 不要写成 ==
            else if ( (s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32 )
            {
                isPalindrome = false;
                break;
            }
            else
            {
                ++left;
                --right;
            }
        }

        return isPalindrome;
    }

private:
    bool isAlphaNum(char &c)
    {
        bool isAlphama = false;

        if (c >= 'a' && c <= 'z')
        {
            isAlphama = true;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            isAlphama = true;
        }
        else if (c >= '0' && c <= '9')
        {
            isAlphama = true;
        }

        return isAlphama;
    }
};
```
