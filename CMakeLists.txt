cmake_minimum_required (VERSION 3.8)

project ("xorshift")

find_package(tl-generator CONFIG REQUIRED)

add_library (xorshift INTERFACE)
target_link_libraries(xorshift INTERFACE tl::generator)
target_include_directories(xorshift
    INTERFACE 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_executable(sample sample/sample.cpp)
if (MSVC)
    target_compile_options(sample PRIVATE "/std:c++latest")
else()
    set_target_properties(sample PROPERTIES CXX_STANDARD 20)
endif()
target_link_libraries(sample PRIVATE xorshift)

include(GNUInstallDirs)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS xorshift
    EXPORT xorshift-export
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT xorshift-export
  FILE
    xorshift-targets.cmake
  NAMESPACE
    cppcon::
  DESTINATION
    ${CMAKE_INSTALL_DATAROOTDIR}/xorshift
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/xorshift-config.cmake
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/xorshift
)

