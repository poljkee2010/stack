#include <stdio.h>
#include <iostream>
#include <locale>
#include <locale.h>
#include <cassert>

using namespace std;

//интерфейс шаблона класса stack:

template <class T>
class stack
{
public:
	stack();
	//size_t count() const; //счетчик
	void push(T const &);
	void printStack();
	T pop();
private:
	T * array_; //массив который будем забивать,array - указатель на массив,который в куче
	size_t count_; //номер элемента,добавляемый в куче
	size_t capacity_;//зарезервированная память (первоначальный размер стека)
	void reallocate();//перераспределение
};

//реализация методов класса:

template <typename T>
void stack<T>::reallocate() 
{
	capacity_ *= 2; //увеличение зарез.памяти в 2 раза
	T* temp = new T[capacity_]; //выделение памяти под массив temp
	for (size_t i = 0; i < count_; ++i) 
	{
		temp[i] = array_[i]; //присваиваем 
	}
	delete[] array_; //освобождаем изначальный участок памяти
	array_ = temp; //??? старому массиву присваиваем новый
}

//конструктор стека
template <typename T>
stack<T>::stack() // инициализация константы
{
	capacity_ = 5;
	array_ = new T[capacity_]; // выделить память под стек
	count_ = 0; // инициализируем текущий элемент нулем;
}

// функция добавления элемента в стек
template <typename T>
void stack<T>::push(T const &value)
{
	// проверяем размер стека
	if (count_ >= capacity_) //если количество элементов больше вместимости
	{
		reallocate(); //то происходит перераспределение памяти
	}
	array_[count_++] = value; // помещаем элемент в стек

}


// функция удаления элемента из стека

template <typename T>
T stack<T>::pop()
{
	// проверяем размер стека
	assert(count_ > 0); // номер текущего элемента должен быть больше 0
	array_[--count_]; // удаляем элемент из стека
	return array_[count_];
}

// вывод стека на экран

template <typename T>
void stack<T>::printStack()
{
	for (int i = count_; i >= 0; i--)
		cout << "[ " << array_[i] << " ]"<< endl;
}

//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	stack<int> stackSymbol;
//	int ct = 0;
//	char ch;
//
//	while (cin>>ch)
//	{
//		stackSymbol.push(ch); // помещаем элементы в стек
//	}
//	cout << endl;
//
//	stackSymbol.printStack(); // печать стека
//
//	//cout << "\n\nУдалим элемент из стека\n";
//
//	//stackSymbol.pop();
//
//	//stackSymbol.printStack(); // печать стека
//
//	system("pause");
//	return 0;
//}

int main()
{
	stack <int> myStack;
	setlocale(LC_ALL, "Rus");

	// заполняем стек
	cout << "Заталкиваем элементы в стек: ";
	int ct = 0;
	while (ct++ <5 )
	{
		int temp;
		cin >> temp;
		myStack.push(temp);
	}

	myStack.printStack(); // вывод стека на экран

	cout << "\nУдаляем два элемента из стека:\n";

	myStack.pop(); // удаляем элемент из стека
	myStack.pop(); // удаляем элемент из стека
	myStack.printStack(); // вывод стека на экран
	system("pause");

	return 0;
}
