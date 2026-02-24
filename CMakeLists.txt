cmake_minimum_required(VERSION 3.16)

project(system_programming_playground C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(lib)

file(GLOB_RECURSE SAMPLE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/hello/*.c"
    "${CMAKE_SOURCE_DIR}/io/*.c"
)

set(_legacy_names "")

foreach(src IN LISTS SAMPLE_SOURCES)
    get_filename_component(name ${src} NAME_WE)
    get_filename_component(dir ${src} DIRECTORY)
    get_filename_component(dir_name ${dir} NAME)
    set(target "${dir_name}_${name}")

    add_executable(${target} ${src})
    target_link_libraries(${target} PRIVATE tlpi_lib)

    list(FIND _legacy_names "${name}" _existing_idx)
    if(_existing_idx EQUAL -1)
        set_target_properties(${target} PROPERTIES OUTPUT_NAME ${name})
        add_custom_target(${name} DEPENDS ${target})
        list(APPEND _legacy_names "${name}")
    endif()
endforeach()
