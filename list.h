#pragma once
#include "queue.h"
class list :
    public queue
{
public:
	list();
	list(float chisl);
	list(const list& deque);
	~list();
	float pop();
	void push(float a);
};

