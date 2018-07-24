1)
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";

        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;

        while(m >= 0 || n >= 0)
        {
        	int p = m >= 0 ? a[m--] - '0' : 0;
        	// 注意不要写成 a[n--]
        	int q = n >= 0 ? b[n--] - '0' : 0;
        	int sum = p + q	+ carry;

        	res = to_string(sum % 2) + res;
        	carry = sum / 2;
        }

        return carry == 0 ? res : "1" + res;
    }
};




2)
class Solution {
public:
    string addBinary(string a, string b) {
        string res;

        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;

        while(m >= 0 || n >= 0)
        {
        	int p = m >= 0 ? a[m--] - '0' : 0;
        	// 注意不要写成 a[n--]
        	int q = n >= 0 ? b[n--] - '0' : 0;
        	int sum = p + q	+ carry;
        	
        	int val = sum % 2;
        	res.insert(res.begin(), val + '0');
        	carry = sum / 2;
        }

        if(carry == 1)
        	res.insert(res.begin(), '1');

        return res;
    }
};