function(add_gba_rom_target ELF_NAME)
    set(GBA_ROM_NAME ${ELF_NAME}.gba)
    add_custom_target(${GBA_ROM_NAME} ALL
        COMMAND ${DEVKITARM_PATH}/bin/arm-none-eabi-objcopy -v -O binary ${ELF_NAME} ${GBA_ROM_NAME}
        COMMAND ${DEVKITPRO_PATH}/tools/bin/gbafix ${GBA_ROM_NAME}
        DEPENDS ${ELF_NAME}
        COMMENT "Creating GBA ROM ${GBA_ROM_NAME}")
    set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${GBA_ROM_NAME})
endfunction(add_gba_rom_target)
