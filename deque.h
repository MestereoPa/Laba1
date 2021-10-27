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
	void push(float newElem);
	void push();
	void get();
	void set();
	void save();
private:
	elem* head = new elem;
	int size;
};

