英文链接: https://leetcode.com/problems/min-stack/  
中文链接: https://leetcode-cn.com/problems/min-stack/


>最小栈跟原来的栈相比就是多了一个功能, 可以返回该栈的最小值。   
使用两个栈来实现  
一个栈来按顺序存储 push 进来的数据, 另一个用来存出现过的最小值


```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        s1.push(x);
        
        // x <= s2.top() 不要写成 s2.top() <= x;
        if (s2.empty() || x <= s2.top()) 
        {
            s2.push(x);
        }
    }
    
    void pop() {
        if (s1.top() == s2.top()) 
        {
            s2.pop();
        }
            
        s1.pop();
    }

    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
    
private:
    stack<int> s1, s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```



再来看另一种解法，这种解法只用到了一个栈，还需要一个整型变量 min_val 来记录当前最
小值，初始化为整型最小值，然后如果需要进栈的数字小于等于当前最小值 min_val，那么
将 min_val 压入栈，并且将 min_val 更新为当前数字。在出栈操作时，先将栈顶元素移出栈，
再判断该元素是否和 min_val 相等，相等的话我们将 min_val 更新为新栈顶元素，再将新栈
顶元素移出栈即可


```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int x) {
        if (x <= min_val) 
        {
            st.push(min_val);
            min_val = x;
        }
        
        st.push(x);
    }
    
    void pop() {
        int t = st.top(); 
        st.pop();
        
        if (t == min_val) 
        {
            min_val = st.top(); 
            // 一定不能遗漏 st.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_val;
    }
    
private:
    int min_val;
    stack<int> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```
