#include <iostream>
#include <stack>
using namespace std;

template <typename T> class CQueue
{
	public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T &node);
	T deleteHead();
	void printQueue();

	private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{}

template <typename T> CQueue<T>::~CQueue(void)
{}

template <typename T> void CQueue<T>::appendTail(const T &element)
{
	stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead()
{
	if(stack2.size() <= 0)
	{
		while(stack1.size() > 0)
		{
			T &data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if(stack2.size() == 0)
	{
		//throw new std::exception("queue is empty");
	}

	T head = stack2.top();
	stack2.pop();

	return head;
}

template <typename T> void CQueue<T>::printQueue()
{
	std::stack<T> stack3;

	while(stack1.size() > 0)
	{
		T tailData = stack1.top();
		stack3.push(tailData);
		stack1.pop();
	}
	
	while(stack2.size() != 0)
	{
		T headData = stack2.top();
		std::cout << headData << std::endl;
		stack2.pop();
	}

	while(stack3.size() != 0)
	{
		T headData = stack3.top();
		std::cout << headData << std::endl;
		stack3.pop();
	}
}

int main()
{
	CQueue<int> testQueue;
	testQueue.appendTail(0);
	testQueue.appendTail(1);
	testQueue.appendTail(2);
	testQueue.appendTail(3);
	testQueue.deleteHead();
	testQueue.appendTail(4);
	testQueue.appendTail(5);
	testQueue.deleteHead();

	testQueue.printQueue();

	return 0;
}
