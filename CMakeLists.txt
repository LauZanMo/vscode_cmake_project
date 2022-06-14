cmake_minimum_required(VERSION 3.10.0)
project(project)

option(BUILD_TEST "Build gtests." OFF)

# for integrating to ROS2, which needs C++14
set(CMAKE_CXX_STANDARD 14)

# set cmake build type
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
endif()

# set executable and library path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

find_package(Boost REQUIRED COMPONENTS system thread date_time)

# append sources, library and include directories
list(APPEND sources
    src/main.cpp
)

list(APPEND thirdparty_libraries
    ${Boost_LIBRARIES}
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

# add executable and link libraries
add_executable(${PROJECT_NAME}
    ${sources}
)

target_link_libraries(${PROJECT_NAME}
    ${thirdparty_libraries}
)

# build test
if(BUILD_TEST)
    find_package(GTest REQUIRED)
    enable_testing()

    list(APPEND test_libraries
        ${Boost_LIBRARIES}
        gtest
    )

    add_executable(${PROJECT_NAME}_test
        ${PROJECT_SOURCE_DIR}/test/test_dummy.cpp
    )

    target_link_libraries(${PROJECT_NAME}_test
        ${test_libraries}
    )
endif()