cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ChessEngine)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include /usr/local/include)

# Add the executable
add_executable(ChessEngine 
    src/main.cpp 
    src/Board.cpp 
    src/Move.cpp 
    src/AIPlayer.cpp
)

# Copy config.txt to the build directory
add_custom_command(
    TARGET ChessEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/config.txt
        $<TARGET_FILE_DIR:ChessEngine>
)

# Link directories (if any specific libraries need to be linked)
# For now, we don't have any additional libraries to link, but if you do, you can add them here:
# target_link_libraries(ChessEngine PRIVATE some_library)