## Домашнее задание #2

## Tasks

- [x] 1. Необходимо добавить метод ```empty```  для класcа ```stack```
- [x] 2. Необходимо добавить примеры для всех методов.
- [x] 3. Необходимо добавить конфигурационный файл ```CMakeLists.txt``` 
- [x] 4. Обеспечить сборку с примерами и сборку без примеров

## Tutorial

```ShellSession
examples/
- init.cpp
- push.cpp
- pop.cpp
- empty.cpp
include/
- stack.hpp
sources/
- main.cpp
CMakeLists.txt
README.md
```

init.cpp terminal message:
```ShellSession
File init.cpp
Created intStack
```

push.cpp terminal message:
```ShellSession
File push.cpp
Number symbols in file push.cpp 6
```

pop.cpp terminal message:
```ShellSession
File pop.cpp
Content file pop.cpp     1 
```

empty.cpp terminal message:
```ShellSession
File empty.cpp
9
8
7
6
5
4
3
2
1
0
File  empty.cpp have 0 elements
```

## Домашнее задание #1

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
## Message terminal
```ShellSession
Elements of STACK:
9
8
7
6
5
4
3
2
1
0
Number of elements in Stack = 0
Stack Empty!
```


