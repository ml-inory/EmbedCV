cmake_minimum_required(VERSION 3.1)

project(EmbedCV)

add_executable(app main.cpp)
install(TARGETS app
	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/install)