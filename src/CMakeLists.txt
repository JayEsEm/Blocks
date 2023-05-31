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

set(FLECS_SHARED OFF CACHE INTERNAL "Will only use static binaries.")

add_library(
    blocks-src
    STATIC
    bl/canvas.cpp
    bl/display.cpp
    bl/game.cpp
    bl/main.cpp
    bl/scene.cpp
    bl/time.cpp
    bl/ecs/system.cpp
    bl/scns/main.cpp
    bl/scns/null.cpp
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
    -pedantic
)

target_include_directories(
    blocks-src
    PUBLIC
    ./
)

target_link_libraries(
    blocks-src
    PRIVATE
    blocks-lib
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
