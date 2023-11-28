#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
	Stack<int> st(100);

	for (int i = 0; i < 10; i++)
		st.push(i + 1);
	cout << "after 10 push(): " << endl;
	cout << st << endl << endl;

	cout << "getMemSize():" << endl;
	cout << st.getMemSize() << endl << endl;

	st.pop();
	cout << "after 1 pop(): " << endl;
	cout << st << endl << endl;

	cout << "getTop: " << endl;
	cout << st.getTop() << endl << endl;

	cout << "isEmpty():" << endl;
	cout << st.isEmpty() << endl << endl;

	return 0;
}
