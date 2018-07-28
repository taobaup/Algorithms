1：递归版 
求x的n次方，for循环让x乘以自己n次，会因超时无法通过 
用递归来折半计算，每次把n缩小一半，这样n最终会缩小到等于0 
任何数的0次方都为1 
这时再往回乘 
如果n是偶数，直接把上次递归得到的值平方后返回 
如果n是奇数，则还需要乘以x 
注意对于n是负数的情况，可以先用相反数计算出结果再取其倒数即可

2：迭代版 
迭代解法，i的初始值为n，若i为2的倍数，则x乘以自己 
否则res乘以x 
i每次循环缩小一半，直到为0停止循环 
最后注意不要遗漏n的正负，如果为负，返回其倒数 
n在最后在判断符号，所以 i != 0 不能写成 i > 0
if(i & 0x1 == 1) 不要写成  if(n & 0x1 == 1)
return n > 0 ? res : 1.0 / res; 一定不要写成  return n > 0 ? res : -res;


class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
            // -n, not n
            return 1.0 / myPower(x, -n);
        else
            return myPower(x, n);
    }

private:
    double myPower(double x, int n)
    {
        if(n == 0)
            return 1.0;
        if(n == 1)
            return x;

        double half = myPower(x, n / 2);
        if(n & 0x1 == 1)
            return x * half * half;
        else
            return half * half;
    }
};




class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(n == 1)
            return x;

        double res = 1.0;
        for(int i = n; i != 0; i /= 2)
        {
            if(i & 0x1 == 1)
                res *= x;
            x *= x;
        }

        // 不要遗漏对n的符号的判断
        return n > 0 ? res : 1.0 / res;
    }
};
