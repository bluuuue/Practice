#pragma once

#include <stack>
#include <assert.h>

template <typename T> class StackWithMin
{
public:
	StackWithMin(void){}
	virtual ~StackWithMin(void){}

	T& top(void);
	const T& top(void) const;
	
	void push(const T& value);
	void pop(void);
	
	const T& min(void) const;
	
	bool empty() const;
	size_t size() const;
	
private:
	std::stack<T> m_data;
	std::stack<T> m_min;
};

tem
