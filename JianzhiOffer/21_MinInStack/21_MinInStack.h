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

