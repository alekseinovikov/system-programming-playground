add_library(tlpi_lib STATIC
    alt_functions.c
    error_functions.c
    get_num.c
)

target_include_directories(tlpi_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
