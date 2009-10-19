MACRO(NEW_EXECUTABLE EXECUTABLE)
    SET (lib_found 0)
    SET (sources)
    SET (libraries)
    FOREACH (arg ${ARGN})
        IF (NOT ${lib_found})
            IF (${arg} STREQUAL "LIBRARIES")
                SET (lib_found 1)
            ELSE ()
                SET (sources ${sources} ${arg})
            ENDIF ()
        ELSE ()
           SET (libraries ${libraries} ${arg})
        ENDIF ()
    ENDFOREACH ()

    ADD_EXECUTABLE(${EXECUTABLE} ${sources})
    TARGET_LINK_LIBRARIES(${EXECUTABLE} ${libraries})
ENDMACRO()
