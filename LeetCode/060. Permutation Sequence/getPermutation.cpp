a1 = k / (n - 1)!
k1 = k % (n - 1)!

a2 = k1 / (n - 2)!
k2 = k1 % (n - 2)!
...

an-1 = kn-2 / 1!
kn-1 = kn-2 / 1!

an = kn-1 / 0!
kn = kn-1 % 0! 

a1a2..an-1an


class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";

        vector<int> f(n, 1);
        // i = 1, not i = 0. otherwise Line xx: division by zero
        for(int i = 1; i < n; ++i)
            f[i] = f[i - 1] * i;

        --k;
        // --i, not ++i
        for(int i = n - 1; i >= 0; --i)
        {
            int j = k / f[i];
            k %= f[i];

            res.push_back(num[j]);
            num.erase(j, 1);
        }

        return res;      
    }
};
