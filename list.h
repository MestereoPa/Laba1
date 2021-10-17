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
	float& operator[] (const int index);
	void push(float a);
	void get();
	void set();
	void save();
	void push(float a, int choise);
private:
	elem* head = new elem;
	int size;
};

