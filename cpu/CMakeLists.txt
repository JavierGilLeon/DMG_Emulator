
add_library(cpu
    src/cpu.c
    src/8bitLoads.c
    src/8bit_arithmetic.c
    src/8bit_logic.c
    src/16bitLoads.c
    src/16bit_arithmetic.c
    src/rotates.c
)

target_include_directories(cpu PUBLIC
 include
 ${CMAKE_SOURCE_DIR}/common
)


target_link_libraries(cpu PUBLIC memory)
