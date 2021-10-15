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
	void get();
	void set();
private:
	elem* head = new elem;
	int size;
};

