cmake_minimum_required(VERSION 2.8)
project(FSM)
set(CMAKE_CXX_FLAGS "--std=c++11 -g")


include_directories(if inc)

set(FSM_HEADERS if/FSM.h if/Transition.h if/State.h if/ID.h if/Message.h if/Base.h)
set(FSM_FILES src/FSM.cpp src/State.cpp src/Transition.cpp src/ID.cpp src/Base.cpp )

add_library(FSMDynamic SHARED ${FSM_FILES})
add_library(FSMStatic STATIC ${FSM_FILES})

set_target_properties(FSMDynamic PROPERTIES OUTPUT_NAME FSM)
set_target_properties(FSMStatic PROPERTIES OUTPUT_NAME FSM)

add_subdirectory(tests)