add_executable(copy
        copy.c
)

add_executable(lseek
        lseek.c
)

target_link_libraries(copy
        PRIVATE
        tlpi_lib
)

target_link_libraries(lseek
        PRIVATE
        tlpi_lib
)
