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
include CMakeFiles/templatecpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/templatecpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/templatecpp.dir/flags.make

CMakeFiles/templatecpp.dir/templatecpp.cpp.o: CMakeFiles/templatecpp.dir/flags.make
CMakeFiles/templatecpp.dir/templatecpp.cpp.o: ../templatecpp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/templatecpp.dir/templatecpp.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/templatecpp.dir/templatecpp.cpp.o -c /Users/kurniawans/Documents/Competitive-Programming/templatecpp.cpp

CMakeFiles/templatecpp.dir/templatecpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/templatecpp.dir/templatecpp.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kurniawans/Documents/Competitive-Programming/templatecpp.cpp > CMakeFiles/templatecpp.dir/templatecpp.cpp.i

CMakeFiles/templatecpp.dir/templatecpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/templatecpp.dir/templatecpp.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kurniawans/Documents/Competitive-Programming/templatecpp.cpp -o CMakeFiles/templatecpp.dir/templatecpp.cpp.s

# Object files for target templatecpp
templatecpp_OBJECTS = \
"CMakeFiles/templatecpp.dir/templatecpp.cpp.o"

# External object files for target templatecpp
templatecpp_EXTERNAL_OBJECTS =

templatecpp: CMakeFiles/templatecpp.dir/templatecpp.cpp.o
templatecpp: CMakeFiles/templatecpp.dir/build.make
templatecpp: CMakeFiles/templatecpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable templatecpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/templatecpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/templatecpp.dir/build: templatecpp

.PHONY : CMakeFiles/templatecpp.dir/build

CMakeFiles/templatecpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/templatecpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/templatecpp.dir/clean

CMakeFiles/templatecpp.dir/depend:
	cd /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kurniawans/Documents/Competitive-Programming /Users/kurniawans/Documents/Competitive-Programming /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug /Users/kurniawans/Documents/Competitive-Programming/cmake-build-debug/CMakeFiles/templatecpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/templatecpp.dir/depend

