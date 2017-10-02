cmake_minimum_required(VERSION 3.0)
	

	set(CMAKE_CXX_STANDARD 11) # Подключение 11-го стандарта
	set(CMAKE_CXX_STANDARD_REQUIRED ON) # Активация 11-го стандарта
	

	option(BUILD_EXAMPLES "Build examples" OFF)
	

	project(stack)
	

add_library(main STATIC /sources/main.cpp) # Добавление статической библиотеки,используя указанные исходные файлы
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) # Список директорий,относительно которых следует искать заголовочные файлы	

	target_include_directories(main PUBLIC
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	  $<INSTALL_INTERFACE:include>
	)
	

	if(BUILD_EXAMPLES)
	  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
	  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
	    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
	    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
	    target_link_libraries(${EXAMPLE_NAME} main)
	    install(TARGETS ${EXAMPLE_NAME}
	      RUNTIME DESTINATION bin
	    )
	  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
	endif()
	

	install(TARGETS stack
	    EXPORT print-config
	    ARCHIVE DESTINATION lib
	    LIBRARY DESTINATION lib
	)
	

	install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
	install(EXPORT print-config DESTINATION cmake)
	add_executable(push ${CMAKE_CURRENT_SOURCE_DIR}/examples/push.cpp)
	add_executable(pop ${CMAKE_CURRENT_SOURCE_DIR}/examples/pop.cpp)
	add_executable(empty ${CMAKE_CURRENT_SOURCE_DIR}/examples/empty.cpp)
	add_executable(init ${CMAKE_CURRENT_SOURCE_DIR}/examples/init.cpp)
	target_link_libraries(pushe stack)
	target_link_libraries(pop stack)
	target_link_libraries(empty stack)
	target_link_libraries(init stack)

