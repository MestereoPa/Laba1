#pragma once
#include "ele.h"
#include <iostream>
#include <fstream>
#include <new>
#include <locale>
using namespace std;
class queue
{
public:
	
	queue();
	virtual ~queue();
	virtual void push(float a) = 0;
	virtual float pop() = 0;
	virtual void get() = 0;
	virtual void set() = 0;
	virtual void save() = 0;
protected:
private:
};

