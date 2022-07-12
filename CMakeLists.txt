cmake_minimum_required(VERSION 3.1)

project(EmbedCV)

include_directories(inc)
include_directories(inc/manager)

add_executable(app main.cpp "inc/config.h" "inc/err_code.h" "inc/manager/solution_manager.h" "inc/manager/model_manager.h" "inc/manager/process_manager.h" "inc/manager/queue_manager.h")
install(TARGETS app
	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/install)