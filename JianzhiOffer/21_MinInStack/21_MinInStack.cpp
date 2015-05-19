#include <iostream>
#include "..\21_MinInStack\21_MinInStack.h"

int main()
{
	StackWithMin<int> stack;
	stack.push(5);
	stack.push(8);
	stack.push(0);

	while(stack.size() > 0)
	{
		std::cout << "Top: " << stack.top() << std::endl;
		std::cout << "Min: " << stack.min() << std::endl;
		stack.pop();
	}


	return 0;
}
