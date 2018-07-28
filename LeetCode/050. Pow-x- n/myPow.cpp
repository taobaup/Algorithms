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
