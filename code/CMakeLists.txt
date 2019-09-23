project(presentation)
cmake_minimum_required(VERSION 3.13)

add_executable(01_intro src/01_intro.cpp)
add_executable(02_intro src/02_intro.cpp)
add_executable(03a_intro src/03a_intro.cpp)
add_executable(03b_intro src/03b_intro.cpp)

add_executable(ausblick_01 src/ausblick/01.cpp)
add_executable(ausblick_02 src/ausblick/02.cpp)

set_property(TARGET 01_intro PROPERTY CXX_STANDARD 17)
set_property(TARGET 02_intro PROPERTY CXX_STANDARD 17)
set_property(TARGET 03a_intro PROPERTY CXX_STANDARD 17)
set_property(TARGET 03b_intro PROPERTY CXX_STANDARD 17)
set_property(TARGET ausblick_01 PROPERTY CXX_STANDARD 17)
set_property(TARGET ausblick_02 PROPERTY CXX_STANDARD 17)
