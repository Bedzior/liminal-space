cmake_minimum_required(VERSION 3.22)

if (NOT DEFINED ENV{DEVKITPRO} OR NOT DEFINED ENV{DEVKITARM})
    message(FATAL_ERROR "devkitARM toolchain not found, aborting")
endif()

set(DEVKITPRO_PATH $ENV{DEVKITPRO})
set(DEVKITARM_PATH $ENV{DEVKITARM})

include(cmake/Tools.cmake)

project(liminal-space)
    message(STATUS "Hello, world!")

    add_executable(LiminalSpace.elf
        src/main.cpp
        include/Intellisense.h
    )

    target_include_directories(LiminalSpace.elf
        PRIVATE
            include
    )

    create_gba_targets()
    target_link_libraries(LiminalSpace.elf
        PRIVATE
            GBA::CORE
    )

    set_target_properties(LiminalSpace.elf PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
    )

    add_executable(LiminalSpace ALIAS LiminalSpace.elf)
    add_gba_rom_target(LiminalSpace)
