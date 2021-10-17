#pragma once
#include "queue.h"
#include "deque.h"
#include "list.h"
#include "stack.h"
#include "elem2.h"
#include <fstream>
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
		void save();
		void load();
		int sizeGet();
	private:
		elem2* head = new elem2;
		int size;
};

