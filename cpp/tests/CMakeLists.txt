cmake_minimum_required(VERSION 3.16)

add_executable(
    test_runner
    test_runner.cpp
    data_structures_tests.cpp
    application_tests.cpp
    algorithms_tests.cpp
    euler_tests.cpp
)

target_link_libraries(
    test_runner
    algorithms
    applications
    data_structures
    euler
    Catch2::Catch2WithMain
)

add_test(
    NAME
        check
    COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/tests/test_runner
)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS applications data_structures algorithms euler)
