# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/linus/Documents/CppMaths/Newton method"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CppMaths2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CppMaths2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CppMaths2.dir/flags.make

CMakeFiles/CppMaths2.dir/main.cpp.o: CMakeFiles/CppMaths2.dir/flags.make
CMakeFiles/CppMaths2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CppMaths2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppMaths2.dir/main.cpp.o -c "/Users/linus/Documents/CppMaths/Newton method/main.cpp"

CMakeFiles/CppMaths2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppMaths2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/linus/Documents/CppMaths/Newton method/main.cpp" > CMakeFiles/CppMaths2.dir/main.cpp.i

CMakeFiles/CppMaths2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppMaths2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/linus/Documents/CppMaths/Newton method/main.cpp" -o CMakeFiles/CppMaths2.dir/main.cpp.s

CMakeFiles/CppMaths2.dir/vektor.cpp.o: CMakeFiles/CppMaths2.dir/flags.make
CMakeFiles/CppMaths2.dir/vektor.cpp.o: ../vektor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CppMaths2.dir/vektor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppMaths2.dir/vektor.cpp.o -c "/Users/linus/Documents/CppMaths/Newton method/vektor.cpp"

CMakeFiles/CppMaths2.dir/vektor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppMaths2.dir/vektor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/linus/Documents/CppMaths/Newton method/vektor.cpp" > CMakeFiles/CppMaths2.dir/vektor.cpp.i

CMakeFiles/CppMaths2.dir/vektor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppMaths2.dir/vektor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/linus/Documents/CppMaths/Newton method/vektor.cpp" -o CMakeFiles/CppMaths2.dir/vektor.cpp.s

CMakeFiles/CppMaths2.dir/matrix.cpp.o: CMakeFiles/CppMaths2.dir/flags.make
CMakeFiles/CppMaths2.dir/matrix.cpp.o: ../matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CppMaths2.dir/matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppMaths2.dir/matrix.cpp.o -c "/Users/linus/Documents/CppMaths/Newton method/matrix.cpp"

CMakeFiles/CppMaths2.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppMaths2.dir/matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/linus/Documents/CppMaths/Newton method/matrix.cpp" > CMakeFiles/CppMaths2.dir/matrix.cpp.i

CMakeFiles/CppMaths2.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppMaths2.dir/matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/linus/Documents/CppMaths/Newton method/matrix.cpp" -o CMakeFiles/CppMaths2.dir/matrix.cpp.s

# Object files for target CppMaths2
CppMaths2_OBJECTS = \
"CMakeFiles/CppMaths2.dir/main.cpp.o" \
"CMakeFiles/CppMaths2.dir/vektor.cpp.o" \
"CMakeFiles/CppMaths2.dir/matrix.cpp.o"

# External object files for target CppMaths2
CppMaths2_EXTERNAL_OBJECTS =

CppMaths2: CMakeFiles/CppMaths2.dir/main.cpp.o
CppMaths2: CMakeFiles/CppMaths2.dir/vektor.cpp.o
CppMaths2: CMakeFiles/CppMaths2.dir/matrix.cpp.o
CppMaths2: CMakeFiles/CppMaths2.dir/build.make
CppMaths2: CMakeFiles/CppMaths2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CppMaths2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppMaths2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CppMaths2.dir/build: CppMaths2
.PHONY : CMakeFiles/CppMaths2.dir/build

CMakeFiles/CppMaths2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CppMaths2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CppMaths2.dir/clean

CMakeFiles/CppMaths2.dir/depend:
	cd "/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/linus/Documents/CppMaths/Newton method" "/Users/linus/Documents/CppMaths/Newton method" "/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug" "/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug" "/Users/linus/Documents/CppMaths/Newton method/cmake-build-debug/CMakeFiles/CppMaths2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CppMaths2.dir/depend

