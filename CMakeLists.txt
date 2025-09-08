cmake_minimum_required(VERSION 3.10)

# Задаем имя проекта. Используется как имя решения и может задавать версию/язык.
project(MyApp)

# Сообщаем CMake где искать header файлы (.h)
include_directories(include)

set(SOURCES
   src/main.cpp   
   src/matrix.cpp
   src/functions.cpp
   src/menu.cpp
)

set(HEADERS
   include/functions.h
   include/matrix.h
   include/const.h
   include/menu.h
)
# Создаем исполняемый файл из всех исходных файлов
add_executable(MyApp ${SOURCES} ${HEADERS})