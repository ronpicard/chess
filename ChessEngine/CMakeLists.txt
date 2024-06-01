cmake_minimum_required(VERSION 3.16)

# Set the project name and C++ standard
project(ChessEngine VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(ChessEngine src/main.cpp src/Board.cpp src/Move.cpp src/AIPlayer.cpp)

# Include directories
target_include_directories(ChessEngine PUBLIC include)