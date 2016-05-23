cmake_minimum_required (VERSION 3.0)

find_package (PkgConfig REQUIRED)
pkg_check_modules (UPM-DFRPH REQUIRED upm-dfrph)
pkg_check_modules (MRAA REQUIRED mraa)

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
  message(STATUS "XXX ${_variableName}=${${_variableName}}")
endforeach()

include_directories(${UPM-DFRPH_INCLUDE_DIRS}
                    ${MRAA_INCLUDE_DIRS}
                    ${UPM-DFRPH_INCLUDEDIR})
link_directories (${MRAA_LIBRARY_DIRS}
                  ${UPM-DFRPH_LIBRARY_DIRS})

project (example_cloader)
add_executable(example_cloader main.cxx)
target_link_libraries (example_cloader ${MRAA_LIBRARIES} ${UPM-DFRPH_LIBRARIES})

# Added for dl function on linux
target_link_libraries (example_cloader -ldl)
