cmake_minimum_required(VERSION 2.8)

set(COMMON_LIBRARIES crypt rt)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb -DDEBUG_MODE")

file(GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)

foreach(testsourcefile ${APP_SOURCES})
    string(REPLACE ".c" "" testname ${testsourcefile})
    add_executable(${testname} ${testsourcefile})
    target_link_libraries(${testname} ${COMMON_LIBRARIES})
endforeach(testsourcefile ${APP_SOURCES})

