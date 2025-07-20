cmake_minimum_required(VERSION 3.10) # Проверка версии CMake.
									# Если версия установленной программы
									# старее указаной, произойдёт аварийный выход.

project(WebSiteStarryTribe)				# Название проекта

find_package(Wt REQUIRED)
find_package(Boost REQUIRED)

set(SOURCE_EXE main.cpp)			# Установка переменной со списком исходников

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

add_subdirectory(modules)				# Добавление подпроекта, указывается имя дирректории

target_link_libraries(main PRIVATE modules Wt::Wt Wt::HTTP Boost::boost)		# Линковка программы с библиотекой