cmake_minimum_required(VERSION 3.16.3)

set(thisProject meterSimulator)

add_executable(${thisProject} 
    metering_hw.c
)

target_include_directories(${thisProject}
    PUBLIC ../commonIncludes/ 
)
