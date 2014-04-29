cmake_minimum_required(VERSION 2.8)

include_directories(if inc)

set(FSM_HEADERS if/FSM.h if/Transition.h if/State.h)
set(FSM_FILES src/FSM.cpp src/State.cpp src/Transition.cpp)

add_library(FSM SHARED ${FSM_FILES})
add_library(FSMStatic STATIC ${FSM_FILES})

set_target_properties(FSMStatic PROPERTIES OUTPUT_NAME FSM)

include_directories(tests)