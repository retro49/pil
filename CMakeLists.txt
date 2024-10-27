cmake_minimum_required(VERSION 3.29)

project(pil)

set(SRC ./src)
set(PIL_LIB_SRC ${SRC}/interpreter)
add_library(
    pilinterpreter
    ${PIL_LIB_SRC}/pil.c        ${PIL_LIB_SRC}/pil.h
)

add_executable(
    pil
    ${SRC}/main.c
)

target_link_libraries(pil pilinterpreter)
