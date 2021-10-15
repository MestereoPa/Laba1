#pragma once
#include "queue.h"
class stack :
    public queue
{
public:

	stack();
	stack(float chisl);
	stack(const stack& stack);
	~stack();
	float pop();
	void get();
	void set();
	void push(float a);
private:
	elem* head = new elem;
	int size;
};

