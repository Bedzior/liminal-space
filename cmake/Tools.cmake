function(add_gba_rom_target ELF_NAME)
    set(GBA_ROM_NAME ${ELF_NAME}.gba)
    add_custom_target(${GBA_ROM_NAME} ALL
        COMMAND ${DEVKITARM_PATH}/bin/arm-none-eabi-objcopy -v -O binary ${ELF_NAME} ${GBA_ROM_NAME}
        COMMAND ${DEVKITPRO_PATH}/tools/bin/gbafix ${GBA_ROM_NAME}
        DEPENDS ${ELF_NAME}
        COMMENT "Creating GBA ROM ${GBA_ROM_NAME}")
    set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${GBA_ROM_NAME})
endfunction(add_gba_rom_target)

function(create_gba_targets)
    if (NOT EXISTS ${DEVKITPRO_PATH}/libgba/lib)
        message(FATAL_ERROR "Missing libGBA library!")
    endif()
    find_library(DEVKITPRO_GBA gba PATHS ${DEVKITPRO_PATH}/libgba/lib)
    find_library(DEVKITPRO_MM mm PATHS ${DEVKITPRO_PATH}/libgba/lib)
    find_library(DEVKITPRO_FAT fat PATHS ${DEVKITPRO_PATH}/libgba/lib)

    # define GBA::CORE
    add_library(GBA::CORE STATIC IMPORTED)
    set_target_properties(GBA::CORE PROPERTIES
        IMPORTED_LOCATION
            ${DEVKITPRO_GBA}
    )
    target_link_directories(GBA::CORE
        INTERFACE
            ${DEVKITARM_PATH}/arm-none-eabi/lib
    )
    target_include_directories(GBA::CORE
        INTERFACE
            ${DEVKITPRO_PATH}/libgba/include
            ${DEVKITARM_PATH}/arm-none-eabi/include
    )

    #define GBA::AUDIO
    add_library(GBA::AUDIO STATIC IMPORTED)
    set_target_properties(GBA::AUDIO PROPERTIES
        IMPORTED_LOCATION
            ${DEVKITPRO_MM}
    )
    target_include_directories(GBA::AUDIO
        INTERFACE
            ${DEVKITPRO_PATH}/libgba/include
    )

    #define GBA::FAT
    add_library(GBA::FAT STATIC IMPORTED)
    set_target_properties(GBA::FAT PROPERTIES
        IMPORTED_LOCATION
            ${DEVKITPRO_FAT}
    )
    target_include_directories(GBA::FAT
        INTERFACE
            ${DEVKITPRO_PATH}/libgba/include
    )
endfunction()
