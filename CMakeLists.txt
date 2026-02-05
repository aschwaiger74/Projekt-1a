cmake_minimum_required(VERSION 3.20)
project(Projekt-1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Damit VS Code / IntelliSense die Compile-Infos bekommt
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pfad zur SFMLConfig.cmake (bei deinem Layout: libs/SFML-3.0.2/lib/cmake/SFML)
set(SFML_DIR "${CMAKE_SOURCE_DIR}/../libs/SFML-3.0.2/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(app src/main.cpp)

target_link_libraries(app PRIVATE SFML::Graphics SFML::Window SFML::System)

# ====== DLLs automatisch neben app.exe kopieren (wichtig für portable Zip) ======
add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/../toolchain/mingw64/bin/libgcc_s_seh-1.dll"
        "$<TARGET_FILE_DIR:app>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/../toolchain/mingw64/bin/libstdc++-6.dll"
        "$<TARGET_FILE_DIR:app>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/../toolchain/mingw64/bin/libwinpthread-1.dll"
        "$<TARGET_FILE_DIR:app>"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/../libs/SFML-3.0.2/bin"
        "$<TARGET_FILE_DIR:app>"
)


target_link_libraries(app
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
