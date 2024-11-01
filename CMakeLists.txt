cmake_minimum_required(VERSION 3.29)

project(pil)

set(SRC ./src)
set(PIL_LIB_SRC ${SRC}/interpreter)
set(PIL_UTIL_SRC ${SRC}/util)
add_library(
    pilinterpreter
    # interpreter
    ${PIL_LIB_SRC}/pil.c        ${PIL_LIB_SRC}/pil.h
    ${PIL_LIB_SRC}/token.c

    # util
    ${PIL_UTIL_SRC}/file.c      ${PIL_UTIL_SRC}/file.h
    ${PIL_UTIL_SRC}/log.c      ${PIL_UTIL_SRC}/log.h
    ${PIL_UTIL_SRC}/panic.h     ${PIL_UTIL_SRC}/unreachable.h
)

add_executable(
    pil
    ${SRC}/main.c
)

target_link_libraries(pil pilinterpreter)
