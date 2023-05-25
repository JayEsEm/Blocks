include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
    GIT_TAG         v3.3.2
)

FetchContent_Declare(
    trompeloeil
    GIT_REPOSITORY  https://github.com/rollbear/trompeloeil.git
    GIT_TAG         v44
)

add_executable(
    blocks-unit
    main.cpp
)

FetchContent_MakeAvailable(catch2)
FetchContent_MakeAvailable(trompeloeil)

target_link_libraries(
    blocks-unit
    PRIVATE
    blocks-src
)

target_link_libraries(
    blocks-unit
    PRIVATE
    Catch2::Catch2WithMain
)

target_link_libraries(
    blocks-unit
    PRIVATE
    trompeloeil
)
