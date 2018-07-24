#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

template<class T>
class StackQueue
{
public:
	StackQueue(){}
	~StackQueue(){}

	void push_back(const T& node);
	T pop_front();
	T front();
	bool empty() const;

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<class T>
void StackQueue<T>::push_back(const T& node)
{
	stack1.push(node);
}

template<class T>
T StackQueue<T>::pop_front()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			int &temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}

	T &res = stack2.top();
	stack2.pop();

	return res;
} 

template<class T>
T StackQueue<T>::front()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			int &temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}

	T res = stack2.top();

	return res;
}

template<class T>
bool StackQueue<T>::empty() const
{
	return stack1.empty() ? true : false;
}

int main()
{
	StackQueue<int> SQ;
	for (int i = 0; i < 10; ++i)
	{
		SQ.push_back(i);
	}

	cout << "empty: " << SQ.empty() << endl;
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "top: " << SQ.front() << endl;
		cout << "pop: " << SQ.pop_front() << endl;
		cout << endl;
	}
	cout << "empty: " << SQ.empty() << endl;

	return 0;
}
