#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
using namespace std;

//интерфейс шаблона класса stack:

template <class T>
class stack
{
public:
    stack() : capacity_(5), count_(0), array_{ new T[capacity_] } {}
    
size_t count() const // используем спецификатор const в конце функции т.к. метод ничего не изменяет,а только возвращает 
{
    return count_;
        }

void push(T const &value)
{
    if (count_ >= capacity_)
    {
    reallocate();
    }
    array_[count_++] = value;
        }
    
T pop()
{
if (count_ == 0) //проверяем размер стека
throw runtime_error("Stack Empty!");
--count_; 
return array_[count_];
}

~stack()
{
delete[] array_;  //освобождение памяти
}
    
bool empty() const
{
if (count_ == 0) //проверяем размер стека
    return true;
return false;
}
private:
T * array_; //массив который будем забивать
size_t count_; //номер элемента
size_t capacity_;  //зарезервированная память (первоначальный размер стека)

void reallocate() //перераспределение
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
};

void StackPop(); //сигнатура функций
void StackEmpty();
void StackInit();
void StackPush();

#endif /*STACK_HPP*/
