#include "queue.h"
#include "stack.h"
#include "deque.h"
int main(void)
{
	setlocale(LC_ALL, "rus");
	deque st;
	st.push(1);
	st.push(3);
	st.get();
	st.pop();
	st.get();
}