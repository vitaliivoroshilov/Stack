#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
	T* pMem;
	int top;
	int memSize;

public:

	Stack(int _n = 100): memSize(_n)
	{
		if (memSize < 0)
			throw("");
		pMem = new T[memSize];
		top = 0;
	}

	Stack(const Stack& s) : memSize(s.memSize), top(s.top)
	{
		pMem = new T[memSize];
		for (int i = 0; i < memSize; i++)
			pMem[i] = s.pMem[i];
	}

	~Stack()
	{
		delete[] pMem;
	}

	void push(T elem)
	{
		if (top == memSize)
		{
			memSize *= 1.3;
			T* tmpMem = new T[memSize];
			for (int i = 0; i < top; i++)
				tmpMem[i] = pMem[i];
			delete[] pMem;
			pMem = tmpMem;
		}
		pMem[top++] = elem;
	}

	int getMemSize()
	{
		return memSize;
	}

	bool isEmpty()
	{
		return top == 0;
	}

	T getTop()
	{
		if (isEmpty())
			throw("");
		else
			return pMem[--top];
	}

	void pop()
	{
		if (isEmpty())
			throw("");
		else
			top--;
	}

	bool operator==(const Stack& s)
	{
		if (top != s.top)
			return false;
		else
			for (int i = 0; i < top; i++)
				if (pMem[i] != s.pMem[i])
					return false;
		return true;
	}

	friend ostream& operator<<(ostream& out, const Stack& s)
	{
		for (int i = 0; i < s.top; i++)
			out << s.pMem[i] << " ";
		return out;
	}
};
