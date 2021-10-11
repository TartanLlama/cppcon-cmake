get_filename_component(xorshift_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(CMakeFindDependencyMacro)

find_dependency(tl-generator REQUIRED)

if(NOT TARGET cppcon::xorshift)
    include("${xorshift_CMAKE_DIR}/xorshift-targets.cmake")
endif()