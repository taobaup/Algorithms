//Climbing Stairs
//cur=cur+prev依次累加即可
class Solution {
public:
    int climbStairs(int n) {
        int prev=0;
        int cur=1;
        
        for(int i=1;i<=n;++i)
        {
            int temp=cur;
            cur+=prev;
            prev=temp;
        }
        
        return cur;
    }
};
