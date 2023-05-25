include(FetchContent)

FetchContent_Declare(
    entt
    GIT_REPOSITORY  https://github.com/skypjack/entt.git
    GIT_TAG         v3.11.1
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
    blocks/main.cpp
)

FetchContent_MakeAvailable(entt)
FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(raylib-cpp)

target_include_directories(
    blocks-src
    PUBLIC
    ./
)

target_link_libraries(
    blocks-src
    PRIVATE
    EnTT::EnTT
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
