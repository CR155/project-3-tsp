cmake_minimum_required(VERSION 3.23)
project(project_3_tsp)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_3_tsp
        catch/test.cpp
        catch/catch.cpp
        tsp.cpp)
