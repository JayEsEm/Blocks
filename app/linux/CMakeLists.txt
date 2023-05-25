add_executable(
    blocks-linux
    main.cpp
)

target_link_libraries(
    blocks-linux
    PRIVATE
    blocks-src
)
