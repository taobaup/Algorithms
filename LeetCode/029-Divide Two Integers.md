英文链接: https://leetcode.com/problems/divide-two-integers/  
中文链接: https://leetcode-cn.com/problems/divide-two-integers/


>不使用乘法、除法和 mod 运算，进行两数的相除   
如果溢出，则返回 INT_MAX

>数值处理问题，如Reverse Integer，注意点在于符号和处理越界的问题   
不能使用乘除法和取余运算，只能考虑用位运算、加减法   
可以用被除数一直减去除数，直到差为0   
迭代次数是结果的大小，比如结果为n，算法复杂度是O(n)   
使用位运算进行优化   
任何一个整数可以表示成以2的幂为底的一组基的线性组合   
即 num = a_0*2^0 + a_1*2^1 + a_2*2^2 + … + a_n*2^n   
基于以上这个公式   
我们先让除数左移得到一个小于被除数的最大基   
每次减去这个基，将结果增加2^k,然后基继续右移迭代，直到基为0   
迭代次数是按2的幂直到超过结果，所以时间复杂度是O(logn)

```
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int flag = (dividend < 0) ^ (divisor < 0);
        int res = 0;
        if(dividend == INT_MIN)
        {
            dividend += abs(divisor);
            ++res;
        }

        if(divisor == INT_MIN)
            return res;

        int digit = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);

        while((dividend >> 1) >= divisor)
        {
            divisor <<= 1;
            ++digit;
        }

        while(digit >= 0)
        {
            if(dividend >= divisor)
            {
                dividend -= divisor;
                res += 1 << digit;
            }

            divisor >>= 1;
            --digit;
        }

        return (flag == 0) ? res : -res;
    }
};
```
