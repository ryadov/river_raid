cmake_minimum_required(VERSION 3.21)
project(river_raid LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(river_raid main4.cpp
        Character.cpp
        Character.hpp
#        Sprites.cpp
#        Sprites.hpp
        Collidable.cpp
        Collidable.hpp
        Shapes.cpp
        Shapes.hpp
        Player.cpp
        Player.hpp
        Enemy.cpp
        Enemy.hpp
        Fuel.cpp
        Fuel.hpp
        Scoreboard.cpp
        Scoreboard.hpp
        Game.hpp
        Game.cpp
#        LeaderBoard.cpp
        Tile.cpp
        Tile.hpp)
target_link_libraries(river_raid PRIVATE sfml-graphics)
target_compile_features(river_raid PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET river_raid POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:river_raid> $<TARGET_FILE_DIR:river_raid> COMMAND_EXPAND_LISTS)
endif()
install(TARGETS river_raid)
