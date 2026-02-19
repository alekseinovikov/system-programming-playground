add_executable(copy
    copy.c
)

target_link_libraries(copy
    PRIVATE
        tlpi_lib
)
