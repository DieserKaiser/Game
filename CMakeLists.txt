cmake_minimum_required(VERSION 4.1)
project(Game C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# raylib-Optionen (vor add_subdirectory setzen)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(raylib-master)

add_executable(Game main.c
        Gamefunk.c
        Gamefunk.h)

target_link_libraries(Game PRIVATE raylib)

# Ordner "resources" bei jedem Build neben die .exe kopieren
# (nur Dateien, die neu oder geändert sind)
if (EXISTS ${CMAKE_SOURCE_DIR}/resources)
    add_custom_target(copy_resources ALL
            COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            ${CMAKE_SOURCE_DIR}/resources
            $<TARGET_FILE_DIR:Game>/resources
            COMMENT "Kopiere resources neben die exe")
    add_dependencies(Game copy_resources)
endif()

# Windows: raylib bringt winmm, gdi32 und opengl32 selbst mit.
# Optional: Konsolenfenster im Release-Build ausblenden
if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    target_link_options(Game PRIVATE -mwindows)
endif()