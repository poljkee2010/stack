## Дз №1

Данная работа посвящена изучению шаблонных классов и работе с ними

## Tasks

- [x] 1.Реализовать шаблонный класс '''stack''' , со следующим интерфейсом:

## Tutorial

Предоставленный интерфейс для реализации программы:
```ShellSession

template <typename T>
class stack
{
public:
    stack();
    size_t count() const;
    void push(T const &);
    T pop();
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};

```
