cmake_minimum_required(VERSION 3.21)
project(river_raid LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(river_raid main.cpp)
target_link_libraries(river_raid PRIVATE sfml-graphics)
target_compile_features(river_raid PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET river_raid POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:river_raid> $<TARGET_FILE_DIR:river_raid> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS river_raid)