cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ChessEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(ChessEngine 
    src/main.cpp
    src/ChessEngine.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Solver.cpp
    src/Evaluator.cpp
)

# Include header files
target_include_directories(ChessEngine PUBLIC include)
