add_executable(mem_layout
        mem_layout.c
)

add_executable(jumps
        jumps.c
)

target_link_libraries(jumps
        PRIVATE
        tlpi_lib
)
