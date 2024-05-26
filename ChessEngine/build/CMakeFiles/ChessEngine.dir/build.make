# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/chess/ChessEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/chess/ChessEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/ChessEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessEngine.dir/flags.make

CMakeFiles/ChessEngine.dir/src/main.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/chess/ChessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ChessEngine.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChessEngine.dir/src/main.cpp.o -c /workspaces/chess/ChessEngine/src/main.cpp

CMakeFiles/ChessEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/chess/ChessEngine/src/main.cpp > CMakeFiles/ChessEngine.dir/src/main.cpp.i

CMakeFiles/ChessEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/chess/ChessEngine/src/main.cpp -o CMakeFiles/ChessEngine.dir/src/main.cpp.s

CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.o: ../src/ChessEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/chess/ChessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.o -c /workspaces/chess/ChessEngine/src/ChessEngine.cpp

CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/chess/ChessEngine/src/ChessEngine.cpp > CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.i

CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/chess/ChessEngine/src/ChessEngine.cpp -o CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.s

CMakeFiles/ChessEngine.dir/src/Board.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/chess/ChessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ChessEngine.dir/src/Board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChessEngine.dir/src/Board.cpp.o -c /workspaces/chess/ChessEngine/src/Board.cpp

CMakeFiles/ChessEngine.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/chess/ChessEngine/src/Board.cpp > CMakeFiles/ChessEngine.dir/src/Board.cpp.i

CMakeFiles/ChessEngine.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/chess/ChessEngine/src/Board.cpp -o CMakeFiles/ChessEngine.dir/src/Board.cpp.s

CMakeFiles/ChessEngine.dir/src/Piece.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/Piece.cpp.o: ../src/Piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/chess/ChessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ChessEngine.dir/src/Piece.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChessEngine.dir/src/Piece.cpp.o -c /workspaces/chess/ChessEngine/src/Piece.cpp

CMakeFiles/ChessEngine.dir/src/Piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/Piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/chess/ChessEngine/src/Piece.cpp > CMakeFiles/ChessEngine.dir/src/Piece.cpp.i

CMakeFiles/ChessEngine.dir/src/Piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/Piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/chess/ChessEngine/src/Piece.cpp -o CMakeFiles/ChessEngine.dir/src/Piece.cpp.s

CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.o: ../src/Evaluator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/chess/ChessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.o -c /workspaces/chess/ChessEngine/src/Evaluator.cpp

CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/chess/ChessEngine/src/Evaluator.cpp > CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.i

CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/chess/ChessEngine/src/Evaluator.cpp -o CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.s

CMakeFiles/ChessEngine.dir/src/Solver.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/Solver.cpp.o: ../src/Solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/chess/ChessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ChessEngine.dir/src/Solver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChessEngine.dir/src/Solver.cpp.o -c /workspaces/chess/ChessEngine/src/Solver.cpp

CMakeFiles/ChessEngine.dir/src/Solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/Solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/chess/ChessEngine/src/Solver.cpp > CMakeFiles/ChessEngine.dir/src/Solver.cpp.i

CMakeFiles/ChessEngine.dir/src/Solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/Solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/chess/ChessEngine/src/Solver.cpp -o CMakeFiles/ChessEngine.dir/src/Solver.cpp.s

# Object files for target ChessEngine
ChessEngine_OBJECTS = \
"CMakeFiles/ChessEngine.dir/src/main.cpp.o" \
"CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.o" \
"CMakeFiles/ChessEngine.dir/src/Board.cpp.o" \
"CMakeFiles/ChessEngine.dir/src/Piece.cpp.o" \
"CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.o" \
"CMakeFiles/ChessEngine.dir/src/Solver.cpp.o"

# External object files for target ChessEngine
ChessEngine_EXTERNAL_OBJECTS =

ChessEngine: CMakeFiles/ChessEngine.dir/src/main.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/src/ChessEngine.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/src/Board.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/src/Piece.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/src/Evaluator.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/src/Solver.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/build.make
ChessEngine: CMakeFiles/ChessEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/chess/ChessEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ChessEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChessEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChessEngine.dir/build: ChessEngine

.PHONY : CMakeFiles/ChessEngine.dir/build

CMakeFiles/ChessEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChessEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChessEngine.dir/clean

CMakeFiles/ChessEngine.dir/depend:
	cd /workspaces/chess/ChessEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/chess/ChessEngine /workspaces/chess/ChessEngine /workspaces/chess/ChessEngine/build /workspaces/chess/ChessEngine/build /workspaces/chess/ChessEngine/build/CMakeFiles/ChessEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ChessEngine.dir/depend

