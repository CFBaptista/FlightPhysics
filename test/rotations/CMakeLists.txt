# Create test executable
add_executable(rotations_test)

# Link test executable against test framework
target_link_libraries(rotations_test PRIVATE
    rotations
    Catch2::Catch2WithMain
)

# Set compile flags for test executable
target_compile_options(rotations_test PRIVATE
    ${COMPILE_FLAGS}
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

# Discover tests from test executable
catch_discover_tests(rotations_test)

# Add source files to test executable
target_sources(rotations_test PRIVATE
    common.cpp
    RollPitchYaw.cpp
)
