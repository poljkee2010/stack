#include <iostream>
#include "stack.hpp"
using namespace std;

int main() 
{
try 
{
        cout << "Elements of STACK:" << endl;

        stack<int>headStack;
        headStack.push(0);
        headStack.push(1);
        headStack.push(2);
        headStack.push(3);
        headStack.push(4);
        headStack.push(5);
        headStack.push(6);
        headStack.push(7);
        headStack.push(8);
        headStack.push(9);

        for (int i = 0; i < 10; i++) 
        {
                cout << headStack.pop() << endl;
        }
        cout << "Number of elements in Stack = " << headStack.count() << endl;
        headStack.pop(); //Вызов исключения т.к. стек пустой
}
        catch (const exception& e) //Обработка исключений
        { 
                cout << e.what() << endl;
        }
return 0;
}
