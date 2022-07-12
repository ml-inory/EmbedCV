cmake_minimum_required(VERSION 3.1)

project(EmbedCV)

find_package(jsoncpp CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)


include_directories(inc)
include_directories(inc/manager)

add_executable(app main.cpp "src/logger.cpp")
target_link_libraries(app PRIVATE glog::glog)
install(TARGETS app
	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/install)