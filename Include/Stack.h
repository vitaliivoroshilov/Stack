#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
	T* begin;
	T* end;
	int size;
	Stack()
	{
		size = 100;
		begin = new T[size];
		end = begin;
	}
	Stack(int _n)
	{
		if (_n < 0)
			throw("");
		size = _n;
		begin = new T[size];
		end = begin;
	}
	Stack(const Stack& s): size(s.size)
	{
		begin = new T[size];
		for (int i = 0; i < size; i++)
			begin[i] = s.begin[i];
		end = begin + (s.end - s.begin);
	}
	~Stack()
	{
		delete[] begin;
	}
	void push(T el)
	{
		if (end - begin == size)
		{
			size = 1.3 * size;
			T* tmp = new T[size];
			for (int i = 0; i < (end - begin); i++)
				tmp[i] = begin[i];
			end = tmp + (end - begin);
			delete[] begin;
			begin = tmp;
		}
		*end = el;
		end++;
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return begin == end;
	}
	T top()
	{
		if (begin == end)
			throw("");
		else
			return *(--end);
	}
	void pop()
	{
		if (begin == end)
			throw("");
		else
			end--;
	}
	bool operator==(const Stack& s)
	{
		if (s.end - s.begin != end - begin)
			return false;
		else
		{
			for (int i = 0; i < end - begin; i++)
				if (begin[i] != s.begin[i])
					return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream& out, const Stack& s)
	{
		for (int i = 0; i < (s.end - s.begin); i++)
			out << s.begin[i] << " ";
		return out;
	}
};