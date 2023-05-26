include(FetchContent)

FetchContent_Declare(
    flecs
    GIT_REPOSITORY  https://github.com/SanderMertens/flecs.git
    GIT_TAG         v3.2.3
)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY  https://github.com/raysan5/raylib.git
    GIT_TAG         4.5.0
)

FetchContent_Declare(
    raylib-cpp
    GIT_REPOSITORY  https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG         v4.5.0
)

add_library(
    blocks-src
    STATIC
    blocks/display.cpp
    blocks/game.cpp
    blocks/main.cpp
)

FetchContent_MakeAvailable(flecs)
FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(raylib-cpp)

target_compile_options(
    blocks-src
    PRIVATE
    -Wall
    -Wextra
    -Wconversion
    -Wsign-conversion
    -Werror
    -pedantic
    -pedantic-errors
)

target_include_directories(
    blocks-src
    PUBLIC
    ./
)

target_link_libraries(
    blocks-src
    PUBLIC
    blocks-inc
)

target_link_libraries(
    blocks-src
    PRIVATE
    flecs::flecs_static
)

target_link_libraries(
    blocks-src
    PRIVATE
    raylib
)

target_link_libraries(
    blocks-src
    PRIVATE
    raylib_cpp
)
