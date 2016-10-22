//Plus One
//从尾到前遍历数组，依次进位即可
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus=1;
        
        for(auto begin=digits.rbegin();begin!=digits.rend();++begin)
        {
            *begin+=plus;
            plus=*begin/10;
            *begin=*begin%10;
        }
        
        if(plus>0)
            digits.insert(digits.begin(),1);
        
        return digits;
    }
};
