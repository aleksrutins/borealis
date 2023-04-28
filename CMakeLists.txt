cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP ON)

project(borealis)

find_package(PkgConfig)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )


add_executable(borealis)

target_sources(borealis
    PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
        src/window.ixx
        src/util/uri.ixx
)

target_sources(borealis PUBLIC main.cxx)
target_link_libraries(borealis ${GTKMM_LIBRARIES})

set_property(TARGET borealis PROPERTY CXX_STANDARD 23)
set_property(TARGET borealis PROPERTY CXX_STANDARD_REQUIRED 20)
set_property(TARGET borealis PROPERTY CXX_EXTENSIONS off)