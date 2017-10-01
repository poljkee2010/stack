cmake_minimum_required(VERSION 3.0) 
project(main) 
set(CMAKE_CXX_STANDARD 11) # Подключение 11-го стандарта
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Активация 11-го стандарта
add_library(main STATIC /sources/main.cpp) # Добавление статической библиотеки,используя указанные исходные файлы
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) # Список директорий,относительно которых следует искать заголовочные файлы

add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/examples/push.cpp) 
add_executable(example2 ${CMAKE_CURRENT_SOURCE_DIR}/examples/pop.cpp) 
add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/examples/init.cpp) 
add_executable(example2 ${CMAKE_CURRENT_SOURCE_DIR}/examples/empty.cpp) 


target_link_libraries(push main) 
target_link_libraries(pop main)
target_link_libraries(empty main)
target_link_libraries(init main)
