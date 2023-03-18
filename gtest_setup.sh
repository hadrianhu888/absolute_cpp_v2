#!/bin/bash

# set up gtest environment

# download googletest from github 
# use shell script to download googletest

git clone "https://github.com/google/googletest.git"

# build googletest

cd googletest
mkdir build
cd build
cmake ..
make

# log all outputs of the make process to a file named make.log

make > make.log

# This is a Windows PC, so I use the following command to copy the files to the corresponding directories

# copy googletest to C:\Program Files\googletest

xcopy ..\googletest C:\Program Files\googletest /E

# copy googletest include files to C:\Program Files\googletest\include

xcopy ..\googletest\include C:\Program Files\googletest\include /E

# copy libgtest.a and libgtest_main.a to C:\Program Files\googletest\lib

xcopy libgtest.a libgtest_main.a C:\Program Files\googletest\lib /E

# copy gtest.pc to C:\Program Files\googletest\lib\pkgconfig

xcopy gtest.pc C:\Program Files\googletest\lib\pkgconfig /E

# copy gtest-config.cmake to C:\Program Files\googletest\lib\cmake

xcopy gtest-config.cmake C:\Program Files\googletest\lib\cmake /E

# copy gtest-config-version.cmake to C:\Program Files\googletest\lib\cmake

xcopy gtest-config-version.cmake C:\Program Files\googletest\lib\cmake /E

# copy gtest and gtest_main to C:\Program Files\googletest\lib

xcopy gtest gtest_main C:\Program Files\googletest\lib /E

# copy gtest_main.h to C:\Program Files\googletest\include

xcopy gtest_main.h C:\Program Files\googletest\include /E

# copy gtest.h to C:\Program Files\googletest\include

xcopy gtest.h C:\Program Files\googletest\include /E

# copy gtest_pred_impl.h to C:\Program Files\googletest\include

xcopy gtest_pred_impl.h C:\Program Files\googletest\include /E

# copy gtest_prod.h to C:\Program Files\googletest\include

xcopy gtest_prod.h C:\Program Files\googletest\include /E

# make a simple test environment and test if googletest works

# create a new directory

mkdir test

# create a new file named test.cpp

# Path: test.cpp

#include <gtest/gtest.h>

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


# create a new file named test.h

# Path: test.h

#ifndef TEST_H

#define TEST_H

#include <gtest/gtest.h>

class Test : public ::testing::Test {
protected:
    Test() {}
    virtual ~Test() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

#endif

# create a new file named test.cpp

# Path: test.cpp

#include "test.h"

TEST_F(Test, test1) {
    EXPECT_EQ(1, 1);
}

# create a new file named CMakeLists.txt

# Path: CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(test)

set(CMAKE_CXX_STANDARD 11)

include_directories(C:/Program\ Files/googletest/include)

link_directories(C:/Program\ Files/googletest/lib)

add_executable(test test.cpp test.h)

target_link_libraries(test gtest gtest_main)

# build test

mkdir build

cd build

cmake ..

make

# run test

./test

# output
#
#[==========] Running 1 test from 1 test case.
#[----------] Global test environment set-up.
#[----------] 1 test from Test
#[ RUN      ] Test.test1
#[       OK ] Test.test1 (0 ms)
#[----------] 1 test from Test (0 ms total)

#[----------] Global test environment tear-down
#[==========] 1 test from 1 test case ran. (0 ms total)
#[  PASSED  ] 1 test.
#


