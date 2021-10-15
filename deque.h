#pragma once
#include "queue.h"
class deque :
    public queue
{
public:
	deque();
	deque(float chisl);
	deque(const deque& deque);
	~deque();
	float pop();
	void push(float a);
	void get();
	void set();
private:
	elem* head = new elem;
	int size;
};

