cmake_minimum_required(VERSION 3.16.3)

set(thisProject resetRequest)

add_executable(${thisProject} 
    resetRequestTest.c
)

target_link_libraries(${thisProject} 
    testUtils
)