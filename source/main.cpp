#include <iostream>
#include "stack.hpp"
using namespace std;

int main() 
{
	try {
		cout << "Elements of STACK:" << endl;
		
		stack<int> intStack;
		intStack.push(0);
		intStack.push(1);
		intStack.push(2);
		intStack.push(3);
		intStack.push(4);
		intStack.push(5);
		intStack.push(6);
		intStack.push(7);
		intStack.push(8);
		intStack.push(9);

		for (int i = 0; i < 10; i++) {
			cout << intStack.pop() << endl;
		}
		
		cout << "Number of elements in Stack = " << intStack.count() << endl;
		intStack.pop(); //Вызов исключения т.к. стек пустой
	}
	catch (const exception& e) //Обработка исключений
	{ 
		cout << e.what() << endl;
	}
}
