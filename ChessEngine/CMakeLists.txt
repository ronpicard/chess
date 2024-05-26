cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ChessEngine)

# Specify the include directories
include_directories(include)

# Add the executable
add_executable(ChessEngine src/main.cpp src/ChessEngine.cpp src/Board.cpp src/Piece.cpp)