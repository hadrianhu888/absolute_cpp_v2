cmake_minimum_required(VERSION 3.0)

project(MyCppUnitTest)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)


# Add CppUnitTest library
set(CPPUNIT_ROOT_DIR "F:\\GitHubRepos\\cppunit\\include\\cppunit")
find_package(CppUnit REQUIRED)
include_directories(${CPPUNIT_INCLUDE_DIR})

# Add test executable
add_executable(MyTest.cpp)
target_link_libraries(MyTest ${CPPUNIT_LIBRARY})

# Add test to CTest
enable_testing()
add_test(MyTest MyTest)
