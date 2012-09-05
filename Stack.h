/* Stack.h - A templated & dynamic LIFO stack */

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
	Stack(int);
	~Stack();
	int push(T element);
	T pop(void);

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
int Stack<T>::push(T element)
{
	if (sp+1 <= size)
	{
		data[sp] = element;
		++sp;
		return 0;
	}
	return -1; /* failed to push, stack is full */
}

template <typename T>
T Stack<T>::pop(void) /* what's proper behavior for popping empty stack? */
{		
	if (sp != 0)
		--sp;

	return data[sp];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

#endif