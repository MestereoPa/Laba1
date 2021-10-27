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
	float pop(int choise);
	void push(float newElem);
	void get();
	void set();
	void save();
	void push();
private:
	elem* head = new elem;
	int size;
};

