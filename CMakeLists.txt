cmake_minimum_required(VERSION 4.0.3) 
project(DMG_Emulator C)

add_subdirectory(memory)

add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME}
	memory

	)
