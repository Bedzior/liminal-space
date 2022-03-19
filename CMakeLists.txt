cmake_minimum_required(VERSION 3.22)

if (NOT DEFINED ENV{DEVKITPRO} OR NOT DEFINED ENV{DEVKITARM})
    message(FATAL_ERROR "devkitARM toolchain not found, aborting")
endif()

set(DEVKITPRO_PATH $ENV{DEVKITPRO})
set(DEVKITARM_PATH $ENV{DEVKITARM})
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/cmake/GBAToolchain.cmake)

include(cmake/Tools.cmake)

project(liminal-space)
    add_executable(LiminalSpace
        src/main.cpp
        include/Intellisense.h
        include/Keypad.hpp
        include/Palette.hpp
    )

    target_include_directories(LiminalSpace
        PRIVATE
            include
    )

    create_gba_targets()
    target_link_libraries(LiminalSpace
        PRIVATE
            GBA::CORE
    )

    set_target_properties(LiminalSpace PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
    )

    add_gba_rom_target(LiminalSpace)
