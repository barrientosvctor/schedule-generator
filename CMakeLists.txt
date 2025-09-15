cmake_minimum_required(VERSION 3.10)
project(ScheduleGenerator
	DESCRIPTION "A schedule generator."
	VERSION 0.1
	LANGUAGES CXX)

set(CXX_STANDARD 11)
set(SRC_FILES
	main.cpp
	vector.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})