/* Stack.h - A templated & dynamic LIFO stack */

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	Stack(int);
	~Stack();
	bool push(T element);
	bool pop(T &retval);

private:
	int sp, size;
	T *data;
};

template <typename T>
Stack<T>::Stack(int s)
{
	sp = 0;
	size = s;
	data = new T [size];
}

template <typename T>
bool Stack<T>::push(T element) /* should this be by reference? */
{
	if (sp+1 <= size)
	{
		data[sp] = element;
		++sp;
		return true;
	}
	return false; /* failed to push, stack is full */
}

template <typename T>
bool Stack<T>::pop(T &retval) /* what's proper behavior for popping empty stack? */
{		
	if (sp != 0)
		--sp;

	retval = data[sp];

	return true;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

#endif