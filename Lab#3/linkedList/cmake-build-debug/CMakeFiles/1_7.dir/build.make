# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/1_7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1_7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_7.dir/flags.make

CMakeFiles/1_7.dir/linkedList.cpp.o: CMakeFiles/1_7.dir/flags.make
CMakeFiles/1_7.dir/linkedList.cpp.o: ../linkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1_7.dir/linkedList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1_7.dir/linkedList.cpp.o -c "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/linkedList.cpp"

CMakeFiles/1_7.dir/linkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1_7.dir/linkedList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/linkedList.cpp" > CMakeFiles/1_7.dir/linkedList.cpp.i

CMakeFiles/1_7.dir/linkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1_7.dir/linkedList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/linkedList.cpp" -o CMakeFiles/1_7.dir/linkedList.cpp.s

# Object files for target 1_7
1_7_OBJECTS = \
"CMakeFiles/1_7.dir/linkedList.cpp.o"

# External object files for target 1_7
1_7_EXTERNAL_OBJECTS =

1_7: CMakeFiles/1_7.dir/linkedList.cpp.o
1_7: CMakeFiles/1_7.dir/build.make
1_7: CMakeFiles/1_7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1_7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_7.dir/build: 1_7

.PHONY : CMakeFiles/1_7.dir/build

CMakeFiles/1_7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1_7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1_7.dir/clean

CMakeFiles/1_7.dir/depend:
	cd "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/cmake-build-debug" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/cmake-build-debug" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#3/linkedList/cmake-build-debug/CMakeFiles/1_7.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/1_7.dir/depend

