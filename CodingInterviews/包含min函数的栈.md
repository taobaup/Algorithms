>定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。


```
class Solution {
public:
    void push(int value) {
        s1.push(value);

        // 不要写成 s2.top() <= value;
        if(s2.empty() || value <= s2.top())
        {
            s2.push(value);
        }    
    }

    void pop() {
        int value = s1.top();
        s1.pop();

        if(s2.top() == value)
            s2.pop();
    }

    int top() {
        return s1.top();    
    }

    int min() {
        return s2.top();
    }

private:
    stack<int> s1, s2;
};
```
