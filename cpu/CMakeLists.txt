
add_library(cpu
    src/cpu.c
)

target_include_directories(cpu PUBLIC
 include
 ${CMAKE_SOURCE_DIR}/include
)
