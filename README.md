# Домашнее задание #1

Данная работа посвящена изучению шаблонов,классов и работе с ними.

## Tasks

- [x] 1.Реализовать шаблонный класс ```stack``` 
- [x] 2.Реализовать перераспределение памяти - увеличить память в 2 раза с сохранием старых элементов.

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
