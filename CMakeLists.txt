cmake_minimum_required(VERSION 4.0.3) 
project(DMG_Emulator C)

add_subdirectory(memory)
add_subdirectory(cpu)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/memory/include
    ${CMAKE_SOURCE_DIR}/cpu/include
)

target_link_libraries(${PROJECT_NAME}
	memory
	cpu
	)
