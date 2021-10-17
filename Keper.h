#pragma once
#include "queue.h"
class Keper
{
	public:

		Keper();
		Keper(queue *newElem);
		~Keper();
		queue* pop();
		queue* operator[] (const int ind);
		void get();
		void push(queue* a);
	private:
		elem* head = new elem;
		int size;
};

