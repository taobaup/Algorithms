stack	member functions:

stack::emplace
stack::empty
stack::pop
stack::push
stack::size
stack::swap
stack::top


queue	member functions:

queue::emplace
queue::empty
queue::pop
queue::push
queue::size
queue::swap
queue::front
queue::back


#include<queue>
#include<exception>

using namespace std;

template <typename T> 
class CStack
{
public:
	CStack() {}
	~CStack() {}

	void push(const T& node);
	T pop();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T>
void CStack<T>::push(const T& node)
{
	if (queue1.size() > 0 && queue2.size() > 0)
	{
		throw new exception("can not push_back");
	}
	else
	{
		if (queue1.size() == 0)
		{
			queue2.push(node);
		}
		else
		{
			queue1.push(node);
		}
	}
}

template<typename T>
T CStack<T>::pop()
{
	if (queue1.size() == 0 && queue2.size() == 0)
	{
		throw new exception("stack is empty");
	}

	T head;
	if (queue1.size() > 0)
	{
		while (queue1.size() > 1)
		{
			T& data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}

		head = queue1.front();
		queue1.pop();
	}
	else
	{
		while (queue2.size() > 1)
		{
			T& data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}

		head = queue2.front();
		queue2.pop();
	}

	return head;
}

void test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	CStack<char> stack;

	stack.push('a');
	stack.push('b');
	stack.push('c');

	char res = stack.pop();
	test(res, 'c');

	res = stack.pop();
	test(res, 'b');

	stack.push('d');
	res = stack.pop();
	test(res, 'd');

	stack.push('e');
	res = stack.pop();
	test(res, 'e');

	res = stack.pop();
	test(res, 'a');

	return 0;
}
