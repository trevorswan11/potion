idf_component_register(SRCS "potion.cpp"
                    INCLUDE_DIRS ".")

if(WIN32)
    set(NULL_DEVICE NUL)
else()
    set(NULL_DEVICE /dev/null)
endif()

execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -E -x c++ - -v
        INPUT_FILE ${NULL_DEVICE}
        ERROR_VARIABLE SYSTEM_INCLUDES
        OUTPUT_QUIET
    )

if(SYSTEM_INCLUDES MATCHES "#include <...> search starts here:(.*)End of search list.")
    set(PATH_BLOCK "${CMAKE_MATCH_1}")

    string(REPLACE "\r" "" PATH_BLOCK "${PATH_BLOCK}")
    string(REPLACE "\n" ";" PATH_LIST "${PATH_BLOCK}")
    foreach(PATH ${PATH_LIST})
        string(STRIP "${PATH}" CLEAN_PATH)
        if(NOT CLEAN_PATH STREQUAL "" AND EXISTS "${CLEAN_PATH}")
            message(STATUS "LSP System Path: ${CLEAN_PATH}")
            include_directories(SYSTEM "${CLEAN_PATH}")
        endif()
    endforeach()
endif()
