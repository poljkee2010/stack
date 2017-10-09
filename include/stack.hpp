#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
using namespace std;

//интерфейс шаблона класса stack:

template <class T>
class stack
{
private:
	T * array_; //массив который будем забивать
	size_t count_; //номер элемента
	size_t capacity_;  //зарезервированная память (первоначальный размер стека)
public:
	stack() noexcept : capacity_(5), count_(0), array_{ new T[5] } {}
	stack(size_t n) noexcept : capacity_{n}, count_(0), array_{ new T[n] } {}

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

	// функция, убирающая значение из стека, и проверяющая номер элемента с вершиной стека на пустоту стека (pop-убираем сверху)
	T top() const noexcept
	{
		return array_[count_];
	}
	T pop() noexcept {
		if (count_ == 0)
		{
			throw runtime_error("Stack is empty!!!"); // генерируем исключение
		}
		--count_; //Снижение счетчика на единицу
		return top();
	}

	~stack() noexcept
	{
		delete[] array_;  //освобождение памяти
	}

	bool empty() const
	{
		if (count_ == 0) //проверяем размер стека
			return true;
		return false;
	}

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

	stack(const stack& s) noexcept //Конструктор копирования
	{
		if (this != &s)
		{
			delete[] array_;
			capacity_ = s.capacity_;
			count_ = s.count_;
			array_ = new T[s.capacity_];
			for (size_t i = 0; i < s.capacity_; ++i)
			{
				array_[i] = s.array_[i];
			}
		}
	}

	stack(stack&& s) noexcept //Конструктор перемещения
	{
		capacity_ = s.capacity_;
		count_ = s.count_;
		array_ = s.array_;
		s.capacity_ = 0;
		s.count_ = 0;
		s.array_ = nullptr;
	}

	stack operator = (const stack& S) noexcept //Оператор присваивания с семантикой копирования
	{
		delete[] array_;
		capacity_ = S.capacity_;
		count_ = S.count_;
		array_ = new T[capacity_];
		for (int i = 0; i < count_; ++i) {
			array_[i] = S.array_[i];
		}
		return *this;
	}

	stack operator = (const stack&& S) noexcept  //Оператор присваивания с семантикой перемещения
	{
		capacity_ = S.capacity_;
		count_ = S.count_;
		array_ = S.array_;
		S.array_ = nullptr;
		S.count_ = 0;
		S.capacity_ = 0;
		return *this;
	}

	T& operator [](int pos) noexcept
	{
		return array_[pos];
	}
};


void StackPop(); //сигнатура функций
void StackEmpty();
void StackInit();
void StackPush();

#endif /*STACK_HPP*/
