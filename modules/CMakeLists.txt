cmake_minimum_required(VERSION 3.10) # Проверка версии CMake.
									# Если версия установленной программы
									# старее указаной, произойдёт аварийный выход.

project(modules)				# Название проекта

set(SOURCE_LIB toc.cpp auw.cpp obw.cpp cw.cpp ciw.cpp)		# Установка переменной со списком исходников

include_directories(include)

add_library(modules STATIC ${SOURCE_LIB})# Создание статической библиотеки