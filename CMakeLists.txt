cmake_minimum_required(VERSION 3.18)      
project(    
    matrixlib-use
    VERSION 0.0.0
    DESCRIPTION "Use cpp library"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

# создаем тестовый exe-файл для динамической библиотеки
add_executable(matrixlib-use
    src/main.cpp
)

# директория
target_include_directories(matrixlib-use  PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
# путь к библиотеке(.dll должен находится также вместе с .exe программы)
target_link_libraries(matrixlib-use PRIVATE "${CMAKE_SOURCE_DIR}/libs/matrixlib/shared-matrixlib.lib")