cmake_minimum_required(VERSION 3.1)

project(EmbedCV)

find_package(jsoncpp CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)


include_directories(inc)
include_directories(inc/manager)
include_directories(inc/processor/input)
include_directories(inc/processor/cv)
include_directories(inc/processor/bussiness)
include_directories(inc/processor/display)

aux_source_directory(src SRC)
aux_source_directory(src/manager SRC)

add_executable(app main.cpp ${SRC})
target_link_libraries(app PRIVATE jsoncpp_lib jsoncpp_object JsonCpp::JsonCpp)
target_link_libraries(app PRIVATE glog::glog)
install(TARGETS app
	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/install)