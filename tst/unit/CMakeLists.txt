include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
    GIT_TAG         v3.3.2
)

FetchContent_Declare(
    fakeit
    GIT_REPOSITORY  https://github.com/eranpeer/FakeIt.git
    GIT_TAG         2.4.0
)

add_executable(
    blocks-unit
    main.cpp
)

FetchContent_MakeAvailable(catch2)
FetchContent_MakeAvailable(fakeit)

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
    FakeIt::FakeIt-catch
)
