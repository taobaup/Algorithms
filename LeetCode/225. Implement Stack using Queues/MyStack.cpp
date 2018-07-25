class MyStack {
private:
	queue<int> queue1;
	queue<int> queue2;
	int top_num;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        top_num =x;
        queue1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x;

        if(queue1.size() > 0)
        {
        	while(queue1.size() > 1)
        	{
        		int &temp = queue1.front();
        		queue1.pop();
        		queue2.push(temp);  
                
                if(queue1.size() == 1)
                    top_num = temp;
        	}
            
        	x = queue1.front();
        	queue1.pop();
        }
        else
        {
        	while(queue2.size() > 1)
        	{
        		int &temp = queue2.front();
        		queue2.pop();
        		queue1.push(temp);
                
                if(queue2.size() == 1)
                    top_num = temp;
        	}

        	x = queue2.front();
        	queue2.pop();
        }

        return x;
    }
    
    /** Get the top element. */
    int top() {
        return top_num;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};




/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
