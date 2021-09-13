#include "queue.h"
#include "stack.h"
#include "deque.h"
#include "list.h"
int main(void)
{
	setlocale(LC_ALL, "rus");
	list st;
	st.set();
	st.push(1);
	st.get();
	st.push(3);
	st.get();
	st.push(7);
	st.get();
	st.pop();
	st.get();
}