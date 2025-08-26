
add_library(memory
    src/memory.c
)

target_include_directories(memory PUBLIC
 include
 ${CMAKE_SOURCE_DIR}/include
)
