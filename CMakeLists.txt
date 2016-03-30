cmake_minimum_required(VERSION 3.4)
project(LearnCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        headers/A_class.h
        headers/date.h
        headers/dynamic_memory.h
        headers/gen_algorithm.h
        headers/HasPtr.h
        headers/io.h
        headers/Person.h
        headers/Screen.h
        headers/seq_container.h
        headers/WIndow_mgr.h
        others/enev
        others/input
        others/note.text
        others/nums
        others/odd
        source/dynamic_memory.cpp
        source/gen_algorithm.cpp
        source/io.cpp
        source/Person.cpp
        source/seq_container.cpp
        main.cpp
        headers/Message.h
        headers/Folder.h
        source/TextQuery.cpp
        headers/TextQuery.h
        headers/QueryResult.h source/StrVec.cpp headers/StrVec.h)

add_executable(LearnCpp ${SOURCE_FILES})
