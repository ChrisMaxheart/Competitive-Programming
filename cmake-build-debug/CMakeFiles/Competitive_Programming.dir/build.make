# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "/Users/kurniawans/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.18/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/kurniawans/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.18/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kurniawans/Documents/Competitive-Programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Competitive_Programming.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Competitive_Programming.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Competitive_Programming.dir/flags.make

CMakeFiles/Competitive_Programming.dir/main.cpp.o: CMakeFiles/Competitive_Programming.dir/flags.make
CMakeFiles/Competitive_Programming.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Competitive_Programming.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Competitive_Programming.dir/main.cpp.o -c /Users/kurniawans/Documents/Competitive-Programming/main.cpp

CMakeFiles/Competitive_Programming.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Competitive_Programming.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kurniawans/Documents/Competitive-Programming/main.cpp > CMakeFiles/Competitive_Programming.dir/main.cpp.i

CMakeFiles/Competitive_Programming.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Competitive_Programming.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kurniawans/Documents/Competitive-Programming/main.cpp -o CMakeFiles/Competitive_Programming.dir/main.cpp.s

CMakeFiles/Competitive_Programming.dir/headerlist.cpp.o: CMakeFiles/Competitive_Programming.dir/flags.make
CMakeFiles/Competitive_Programming.dir/headerlist.cpp.o: ../headerlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Competitive_Programming.dir/headerlist.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Competitive_Programming.dir/headerlist.cpp.o -c /Users/kurniawans/Documents/Competitive-Programming/headerlist.cpp

CMakeFiles/Competitive_Programming.dir/headerlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Competitive_Programming.dir/headerlist.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kurniawans/Documents/Competitive-Programming/headerlist.cpp > CMakeFiles/Competitive_Programming.dir/headerlist.cpp.i

CMakeFiles/Competitive_Programming.dir/headerlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Competitive_Programming.dir/headerlist.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kurniawans/Documents/Competitive-Programming/headerlist.cpp -o CMakeFiles/Competitive_Programming.dir/headerlist.cpp.s

# Object files for target Competitive_Programming
Competitive_Programming_OBJECTS = \
"CMakeFiles/Competitive_Programming.dir/main.cpp.o" \
"CMakeFiles/Competitive_Programming.dir/headerlist.cpp.o"

# External object files for target Competitive_Programming
Competitive_Programming_EXTERNAL_OBJECTS =

Competitive_Programming: CMakeFiles/Competitive_Programming.dir/main.cpp.o
Competitive_Programming: CMakeFiles/Competitive_Programming.dir/headerlist.cpp.o
Competitive_Programming: CMakeFiles/Competitive_Programming.dir/build.make
Competitive_Programming: CMakeFiles/Competitive_Programming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Competitive_Programming"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Competitive_Programming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Competitive_Programming.dir/build: Competitive_Programming

.PHONY : CMakeFiles/Competitive_Programming.dir/build

CMakeFiles/Competitive_Programming.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Competitive_Programming.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Competitive_Programming.dir/clean

CMakeFiles/Competitive_Programming.dir/depend:
	cd /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kurniawans/Documents/Competitive-Programming /Users/kurniawans/Documents/Competitive-Programming /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug/CMakeFiles/Competitive_Programming.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Competitive_Programming.dir/depend

