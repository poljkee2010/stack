#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <stdexcept>
using namespace std;

//интерфейс шаблона класса stack:

template <class T>
class stack
{
public:
	stack();
	size_t count() const; 
	void push(T const &);
	T pop();
private:
	T * array_; //массив который будем забивать
	size_t count_; //номер элемента,добавляемый в куче
	size_t capacity_;  //зарезервированная память (первоначальный размер стека)
	void reallocate(); //перераспределение
};

//реализация методов класса:

template <typename T>
void stack<T>::reallocate()
{
	capacity_ *= 2; //увеличение зарез.памяти в 2 раза
	T* temp = new T[capacity_]; //выделение памяти под массив temp
	for (size_t i = 0; i < count_; ++i)
	{
		temp[i] = array_[i]; 
	}
	delete[] array_; //освобождаем изначальный участок памяти
	array_ = temp;   //меняем указатель
}

template <typename T>
stack<T>::stack() 
{
	capacity_ = 5;
	array_ = new T[capacity_]; // выделить память под стек
	count_ = 0; // инициализируем текущий элемент нулем;
}

template <typename T>
void stack<T>::push(T const &value)
{
	if (count_ >= capacity_) 
	{
		reallocate(); 
	}
	array_[count_++] = value; 
}

template <typename T>
T stack<T>::pop()
{
	if (count_ == 0) //проверяем размер стека
		throw runtime_error("Stack Empty!"); 	
	array_[--count_]; // удаляем элемент из стека
	return array_[count_];
}

#endif /* Stack_h */
