
set(FSM_TESTS_BASIC_FILES src/main.cpp)

add_executable(FSM_Basic ${FSM_TESTS_BASIC_FILES})

TARGET_LINK_LIBRARIES(FSM_Basic FSMDynamic)
