add_library(
    blocks-src
    STATIC
    blocks/main.cpp
)

target_include_directories(
    blocks-src
    PUBLIC
    ./
)
