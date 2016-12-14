题目：用两个栈实现队列

解题思路：
入队：直接push进stack1
出队：判断stack2是否为空
如果为空，则将stack1中所有元素pop，并push进栈stack2，取出stack2的栈顶;
如果不为空，直接取出stack2的栈顶

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int &temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
		}

		int result = stack2.top();
		stack2.pop();

		return result;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
