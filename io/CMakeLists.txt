add_executable(copy
        copy.c
)

add_executable(lseek
        lseek.c
)

add_executable(atomic_append
        atomic_append.c
)

target_link_libraries(copy
        PRIVATE
        tlpi_lib
)

target_link_libraries(lseek
        PRIVATE
        tlpi_lib
)

target_link_libraries(atomic_append
        PRIVATE
        tlpi_lib
)