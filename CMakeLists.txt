cmake_minimum_required(VERSION 4.0.3) 
project(DMG_Emulator C)

add_subdirectory(cpu)
add_subdirectory(apu)
add_subdirectory(input)
add_subdirectory(memory)
add_subdirectory(rom)
add_subdirectory(ppu)


add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME}
    cpu
    apu
    input
    memory
    rom
    ppu
)