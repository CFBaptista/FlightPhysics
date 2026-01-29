# Add inteface library
add_library(rotations INTERFACE)

# Include directories for interface library
target_include_directories(rotations INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Set compile options for interface library
target_compile_options(rotations INTERFACE
    ${COMPILE_FLAGS}
    ${COVERAGE_FLAGS}
)

# Set link options for interface library
target_link_options(rotations INTERFACE
    ${COVERAGE_FLAGS}
)

# Add source files to interface library
target_sources(rotations INTERFACE
    common.hpp
    RollPitchYaw.hpp
)
