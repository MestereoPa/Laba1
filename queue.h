#pragma once
#include "ele.h"
#include <iostream>
#include <new>
#include <locale>
using namespace std;
class queue
{
public:
	
	queue();
	queue(float chisl);
	queue(const queue& queue);
	virtual ~queue();
	virtual void push(float a);
	virtual float pop();
	void get();
	void set();

protected:
	elem* head = new elem;
	int size;
private:
};

